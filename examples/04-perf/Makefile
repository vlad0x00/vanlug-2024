.PHONY: all clean

all: cache cache-bypass

cache: cache.cpp
	g++ -O3 -std=c++20 -o $@ $<

cache-bypass: cache_bypass.cpp
	g++ -O3 -std=c++20 -o $@ $<

clean:
	$(RM) cache cache-bypass
