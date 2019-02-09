
SRC = Problem28.cpp

all:main
main:$(SRC)
		g++ -o main $(SRC)
run:main
		./main
file:
		touch $(SRC)
clean:
		rm main
edit:$(SRC)
		vi $(SRC)
