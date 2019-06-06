#include <iostream>
#include <cassert>
#include "matrix.h"

int main()
{
 	matrix <int, 0> matr;

	matr[0][0] = 0;
	matr[1][1] = 1;
	matr[2][2] = 2;
	matr[3][3] = 3;
	matr[4][4] = 4;
	matr[5][5] = 5;
	matr[6][6] = 6;
	matr[7][7] = 7;
	matr[8][8] = 8;
	matr[9][9] = 9;
	
	matr[0][9] = 9;
	matr[1][8] = 8;
	matr[2][7] = 7;
	matr[3][6] = 6;
	matr[4][5] = 5;
	matr[5][4] = 4;
	matr[6][3] = 3;
	matr[7][2] = 2;
	matr[8][1] = 1;
	matr[9][0] = 0;

	for (auto i = 1 ; i < 9 ; i++)
	{
		for (auto j = 1 ; j < 9; j++)
		{
			std::cout << matr(i,j) << " " ;
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "ocuppied cells = " << matr.size()  <<  std::endl;
	std::cout << std::endl;

	for (auto c: matr)
	{
		int x;
		int y;
		int v;
		std::tie(x,y,v) = c;
		std::cout << x << y << v << std::endl;
	}

	std::cout << std::endl;
	((matr[100][100] = 314) = 0) = 217;
	std::cout << matr(100,100) << std::endl;
	
	return 1;
}
