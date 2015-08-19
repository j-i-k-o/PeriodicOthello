#include <iostream>
#include "../include/othello.h"

using namespace Othello;

int main(int argc, char const* argv[])
{
	Othello<8> board;

	while(true)
	{
		int m,n;
BLACK_TURN:
		board.print();
		std::cout << "black turn" << std::endl;
		std::cin >> m;
		std::cin >> n;
		if(board.step(m, n, BLACK) == false)
		{
			std::cout << "cannot place here." << std::endl;
			goto BLACK_TURN;
		}

WHITE_TURN:
		board.print();
		std::cout << "white turn" << std::endl;
		std::cin >> m;
		std::cin >> n;
		if(board.step(m, n, WHITE) == false)
		{
			std::cout << "cannot place here." << std::endl;
			goto WHITE_TURN;
		}
	}
}
