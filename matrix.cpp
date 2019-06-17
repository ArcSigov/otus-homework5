#include <iostream>
#include <cassert>
#include "matrix.hpp"


int main()
{
 	 matrix <int, 0> matr;

	for (auto i = 0 ; i < 10 ; i++)
	{
		static auto j = 9;
		matr[i][i] = i;
		matr[i][j] = j;
		j--;
	}

	for (auto i = 1 ; i < 9 ; i++)
	{
		for (auto j = 1 ; j < 9; j++)
		{
			std::cout << matr[i][j] << " ";
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
	 std::cout << matr[100][100] << std::endl;
	return 1;
}
