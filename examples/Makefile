.PHONY: all clean

all:
	$(MAKE) -C 01-flamegraphs
	$(MAKE) -C 02-cache
	$(MAKE) -C 03-fadvise
	$(MAKE) -C 04-cache-bypass
	$(MAKE) -C 05-perf
	$(MAKE) -C 06-shm
	$(MAKE) -C 07-flags
	$(MAKE) -C 08-godbolt
	$(MAKE) -C 09-omp

clean:
	$(MAKE) -C 01-flamegraphs clean
	$(MAKE) -C 02-cache clean
	$(MAKE) -C 03-fadvise clean
	$(MAKE) -C 04-cache-bypass clean
	$(MAKE) -C 05-perf clean
	$(MAKE) -C 06-shm clean
	$(MAKE) -C 07-flags clean
	$(MAKE) -C 08-godbolt clean
	$(MAKE) -C 09-omp clean
