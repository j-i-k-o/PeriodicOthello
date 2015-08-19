#pragma once
#include <iostream>
#include <vector>
#include <utility>

namespace Othello{
	enum STATE{
		EMPTY,
		BLACK,
		WHITE,
	};

	template <int M>
		class Othello{
			static_assert(M%2==0, "the number of board must be even.");
			static_assert(M>0, "the number of board must be larger than 0.");
			private:
				STATE _board[M][M];
			public:
				constexpr static int P(int n) //周期的境界条件
				{
					return n%M + (n<0?M:0);
				}

				STATE& board(int m, int n)
				{
					return _board[P(m)][P(n)];
				}

				Othello()
				{
					initialize();
				}

				void initialize()
				{
					for(int i=0; i<M; i++)
					{
						for(int j=0; j<M; j++)
						{
							board(i,j) = EMPTY;
						}
					}

					//最初にコマを置く
					board(M/2-1, M/2-1) = WHITE;
					board(M/2-1, M/2) = BLACK;
					board(M/2, M/2-1) = BLACK;
					board(M/2, M/2) = WHITE;
				}

				bool step(int m, int n, STATE state)
				{
					//(m,n)  たて　よこ
					bool success = false;

					//コマがすでに盤上にあったらfalse
					if(board(m, n) != EMPTY)
						return false;

					STATE enemyStat;
					if(state == WHITE) enemyStat = BLACK;
					if(state == BLACK) enemyStat = WHITE;

					//direction
					std::vector<std::pair<int,int>> drct_array;
					drct_array.emplace_back( 0, 1); //right
					drct_array.emplace_back( 0,-1); //left
					drct_array.emplace_back(-1, 0); //up
					drct_array.emplace_back( 1, 0); //low
					drct_array.emplace_back(-1, 1); //upperright
					drct_array.emplace_back(-1,-1); //upperleft
					drct_array.emplace_back( 1, 1); //lowerright
					drct_array.emplace_back( 1,-1); //lowerleft

					for(auto drct : drct_array)
					{
						for(int count=1; count<=M; count++)
						{
							STATE curStat = board(m+drct.first*count, n+drct.second*count);
							if(curStat == enemyStat)
							{
								continue;
							}
							else if((curStat == state)&&(count>1))
							{
								success = true;
								for(int i=count; i>=0; i--)
								{
									board(m+drct.first*i, n+drct.second*i) = state;
								}
								break;
							}
							else
							{
								break;
							}
						}
					}

					return success;
				}

				void print()
				{
					for(int i=0; i<M; i++)
					{
						for(int j=0; j<M; j++)
						{
							if(board(i, j) == WHITE) std::cout << "W";
							if(board(i, j) == BLACK) std::cout << "B";
							if(board(i, j) == EMPTY) std::cout << ".";
						}
						std::cout << std::endl;
					}
				}

		};
}
