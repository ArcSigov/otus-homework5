#include <iostream>
#include <cassert>
#include "matrix.h"

int main()
{
  	matrix <int, -1> matr_test;
	matrix <int, 0> matr;

	auto a = matr_test[0][0];

	assert(a == -1);
	assert(matr_test.size() == 0);

	matr_test[100][100] = 314;
	
	assert (matr_test[100][100] == 314);

	assert (matr_test.size() == 1);

	// for (auto c: matr)
	// {

	// }


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

	std::cout << "for_test=" << matr[9][0].cell_value() << std::endl;
	std::cout << "ocuppied cells = " << matr.size()  <<  std::endl;
	return 1;
}

