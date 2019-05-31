#pragma once

#include <map>
#include "submatrix.h"



template <typename T, int def_val>
class matrix  {
	static constexpr int _default = def_val;
public:

	 matrix();
	~matrix();

	submatrix<T,_default>& operator[](const int row)
	{
		return _matrix[row];
	};

	void size();
	void push_element (const int row, const int column, const T& value);
	void erase_element(const int row,const int column);


private:
	int occupied_cells = 0;
	std::map<const int,submatrix<T,_default>> _matrix{};
};


template <typename T, int def_val>
matrix<T,def_val>::matrix()
{

}

template <typename T, int def_val>
matrix<T,def_val>::~matrix()
{

}

template <typename T, int def_val>
void matrix<T,def_val>::push_element(const int row, const int column, const T& value)
{
	_matrix[row].insert(column,value);
}

template <typename T, int def_val>
void matrix<T,def_val>::erase_element(const int row, const int column)
{
	_matrix[row].erase(column);
}


