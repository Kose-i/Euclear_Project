
SRC = Problem11.cpp

all:main
main:$(SRC)
		g++ -o main $(SRC)
clean:
		rm main
