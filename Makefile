
SRC = Problem26.cpp

all:main
main:$(SRC)
		g++ -o main $(SRC)
clean:
		rm main
