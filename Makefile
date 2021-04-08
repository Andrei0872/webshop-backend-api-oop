.DEFAULT_GOAL := run

.PHONY: run build clean

run: build
	./main

build:
	# -Wall -Wextra -pedantic
	g++ -g -Wall -Wextra -pedantic -pthread *.cpp -o main

clean:
	rm main