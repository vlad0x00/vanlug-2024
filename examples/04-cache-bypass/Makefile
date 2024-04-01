.PHONY: clean

cache-bypass: cache_bypass.cpp
	g++ -O3 -std=c++20 -o $@ $< -march=native

clean:
	$(RM) cache-bypass
