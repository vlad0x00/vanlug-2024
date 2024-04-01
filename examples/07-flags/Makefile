.PHONY: all clean comment-out-march uncomment-march

all: flags llama.cpp/main

comment-out-march:
	@sed -i '/MK_CFLAGS.*-march=native/s/-march=native/#-march=native/' llama.cpp/Makefile
	@sed -i '/HOST_CXXFLAGS.*-march=native/s/-march=native/#-march=native/' llama.cpp/Makefile

uncomment-march:
	@sed -i '/MK_CFLAGS.*#-march=native/s/#-march=native/-march=native/' llama.cpp/Makefile
	@sed -i '/HOST_CXXFLAGS.*#-march=native/s/#-march=native/-march=native/' llama.cpp/Makefile

llama.cpp/models/llama-2-13b-chat.Q5_K_M.gguf:
	ln -s ~/projects/llama.cpp/models/llama-2-13b-chat.Q5_K_M.gguf llama.cpp/models/

llama.cpp/main: llama.cpp/Makefile llama.cpp/models/llama-2-13b-chat.Q5_K_M.gguf
	$(MAKE) -C llama.cpp main

flags: flags.cpp
	g++ -O3 -std=c++20 -o $@ $< # -ffast-math # #-march=native

clean:
	$(RM) flags
	$(MAKE) -C llama.cpp clean
