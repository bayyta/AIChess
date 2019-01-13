#include "board.h"
#include <iostream>
#include <thread>

int main()
{
	using namespace chess;

	Board board;
	board.printBoard();

	while (true)
	{
		std::cin.get();
		board.makeMove();
		board.printBoard();
	}

	system("PAUSE");
	return 0;
}