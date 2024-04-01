.PHONY: all clean

all: flamegraph.svg

flame: flame.cpp
	g++ -std=c++20 -o $@ $< -g

perf.data: flame
	perf record -F 99 -g -- ./flame

out.perf: perf.data
	perf script > $@

out.folded: out.perf
	FlameGraph/stackcollapse-perf.pl $< > $@

flamegraph.svg: out.folded
	FlameGraph/flamegraph.pl $< >$@

clean:
	$(RM) flame perf.data out.perf out.folded flamegraph.svg
