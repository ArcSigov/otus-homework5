#include <iostream>
#include <cassert>
#include "matrix.h"

int main()
{
	matrix <int, -1> matr;



//	matr.push_element(1000,1007,8);
//	matr.push_element(1000,1007,18);

	//matr.push_element(1000,1007,15);
	matr[1000][1008] = 16;
	auto b = matr[1000][1008];
	auto a = matr[1][1];

	std::cout <<"a="<< a << " b=" <<  b  << std::endl;
	return 1;
}
