
SRC = Problem24.cpp

all:main
main:$(SRC)
		g++ -o main $(SRC)
run:main
		./main
clean:
		rm main
edit:$(SRC)
		vi $(SRC)
