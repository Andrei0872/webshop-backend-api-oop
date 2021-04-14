.DEFAULT_GOAL := run

.PHONY: run build clean

run: build
	./main

build:
	# -Wall -Wextra -pedantic
	g++ -g -pthread *.cpp -o main

clean:
	rm main