FC.out: src/main.cpp src/pipe.cpp src/bird.cpp src/menu.cpp
	g++ -lncurses src/main.cpp src/pipe.cpp src/bird.cpp src/menu.cpp -o FC.out

