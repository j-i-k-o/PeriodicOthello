/*******************************************************************************
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 j-i-k-o
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************/

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
