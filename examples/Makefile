.PHONY: all clean

all:
	$(MAKE) -C 01-cache
	$(MAKE) -C 02-fadvise
	$(MAKE) -C 03-cache-bypass
	$(MAKE) -C 04-perf
	$(MAKE) -C 05-shm
	$(MAKE) -C 06-flags
	$(MAKE) -C 07-godbolt
	$(MAKE) -C 08-omp

clean:
	$(MAKE) -C 01-cache clean
	$(MAKE) -C 02-fadvise clean
	$(MAKE) -C 03-cache-bypass clean
	$(MAKE) -C 04-perf clean
	$(MAKE) -C 05-shm clean
	$(MAKE) -C 06-flags clean
	$(MAKE) -C 07-godbolt clean
	$(MAKE) -C 08-omp clean
