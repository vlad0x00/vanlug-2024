.PHONY: clean all

all: large_file fadvise

large_file:
	./create-large-file

fadvise: fadvise.cpp
	g++ -O3 -std=c++20 -o $@ $<

clean:
	$(RM) fadvise large_file
