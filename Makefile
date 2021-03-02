.DEFAULT_GOAL := run

.PHONY: run build clean

run: build
	./main

build:
	g++ -pthread ./main.cpp -o main

clean:
	rm main