#include "../common.hpp"

#include <emmintrin.h> 

#include <cstdint>
#include <cstdlib>

__m128i FILTER = _mm_set1_epi16(0x00FF);

__m128i apply_filter(__m128i &pixel_data) {
    return _mm_and_si128(pixel_data, FILTER);
}

void process_image_nontemporal(uint8_t* src, uint8_t* dst, size_t num_pixels) {
    for (size_t i = 0; i < num_pixels; i += 16) {
        __m128i pixel_data = _mm_load_si128((__m128i*)(src + i));
        __m128i processed_data = apply_filter(pixel_data);
        _mm_stream_si128((__m128i*)(dst + i), processed_data);
    }
    _mm_sfence();
}

void process_image_regular(uint8_t* src, uint8_t* dst, size_t num_pixels) {
    for (size_t i = 0; i < num_pixels; i += 16) {
        __m128i pixel_data = _mm_load_si128((__m128i*)(src + i));
        __m128i processed_data = apply_filter(pixel_data);
        _mm_store_si128((__m128i*)(dst + i), processed_data);
    }
}

constexpr __uint128_t FILTER_UINT128_T = ((__uint128_t)0x00FF00FF00FF00FFULL << 64) | 0x00FF00FF00FF00FFULL;

void apply_filter_uint128_t(__uint128_t &pixel_data) {
    pixel_data &= FILTER_UINT128_T;
}

void process_image_uint128_t(uint8_t* src, uint8_t* dst, size_t num_pixels) {
    for (size_t i = 0; i < num_pixels; i += 16) {
        __uint128_t &pixel_data = *reinterpret_cast<__uint128_t*>(src + i);
        apply_filter_uint128_t(pixel_data);
        *reinterpret_cast<__uint128_t*>(dst + i) = pixel_data;
    }
}

void write_to_file(uint8_t* dst, size_t num_pixels) {
    FILE* file = fopen("/dev/null", "wb");
    fwrite(dst, sizeof(uint8_t), num_pixels, file);
    fclose(file);
}

int main() {
    const size_t num_pixels = 1024L * 1024L * 1024L * 10L;
    const size_t num_bytes = num_pixels * sizeof(uint8_t);
    uint8_t* src = static_cast<uint8_t*>(std::aligned_alloc(16, num_bytes));
    uint8_t* dst = static_cast<uint8_t*>(std::aligned_alloc(16, num_bytes));

    // Warm up the cache
    //process_image_regular(src, dst, num_pixels);
    process_image_nontemporal(src, dst, num_pixels);

    //BENCHMARK(process_image_uint128_t(src, dst, num_pixels), "uint128_t: ");
    //BENCHMARK(process_image_regular(src, dst, num_pixels), "Regular: ");
    //BENCHMARK(process_image_nontemporal(src, dst, num_pixels), "Non-temporal: ");

    write_to_file(dst, num_pixels);

    return 0;
}
