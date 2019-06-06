#pragma once

#include <map>
#include <tuple>
#include <memory>
#include <type_traits>


#include "column.h"
#include "matrix_iterator.h"

template <typename T, T def_val>
class matrix{
	static constexpr T _default = def_val;
	using matrix_pool = std::map<const int, column<T>>;
	using output_pool = std::map<const int, std::tuple<const int,const int,T>>;
public:
	 matrix();
	 matrix(const matrix&) = delete;
	 matrix operator = (matrix& other) = delete;
	~matrix();
	 auto& operator[](const int row);
	 auto  operator()(const int row, const int column);
	 auto begin();
	 auto end();
     	 auto size() const; 
	 void set(const int row, const int column, T value);
	 
private:
	matrix_pool _matrix{};
	output_pool output;
};


template <typename T, T def_val>
matrix<T,def_val>::matrix(){}

template <typename T, T def_val>
matrix<T,def_val>::~matrix(){}



template <typename T, T def_val>
auto matrix<T,def_val>::size() const
{
	 auto asize = 0;
	 for (auto it = _matrix.cbegin() ; it != _matrix.cend(); ++it)
	 {
		  asize += it->second.size();	
	 }
	return asize;
}

template <typename T, T def_val>
auto& matrix<T,def_val>::operator[](const int row) 
{
	auto it = _matrix.find(row);
	if (it == _matrix.end())
	{
		column<T> column(def_val);
		bool b;
		std::tie(it,b) = _matrix.emplace(row,column);
	}
	return it->second;
}

template <typename T, T def_val>
auto matrix<T,def_val>::begin()
{
	auto pos = 0;
	auto it = _matrix.begin();
	while (it!=_matrix.end())
	{
		auto it1 = it->second.column_begin();
		while (it1 != it->second.column_end())
		{
			if (it1->second.cell_size())
			{
				output.emplace(pos,std::make_tuple(it->first,it1->first,it1->second.get_value()));
				pos++;
			}		
			it1++;
		}
		it++;
	}
 	return  matrix_iterator<T>(output.begin());
}

template <typename T, T def_val>
auto matrix<T,def_val>::end()
{
	return matrix_iterator<T>(output.end());
}

template <typename T, T def_val>
void matrix<T,def_val>::set(const int _row, const int _column, T _value)
{
	auto it = _matrix.find(_row);

	if (it!= _matrix.end())
	{
		it->second[_column]=_value;
	}
	else
	{
		bool b; 
		std::tie(it,b) = _matrix.emplace(_row,column<T>(_default));
		it->second[_column] = _value;
	}
}

template <typename T, T def_val>
auto matrix<T,def_val>::operator()(const int row, const int column)
{
	auto it = _matrix.find(row);
	
	if (it != _matrix.end())
	{
		return it->second[column].get_value();
	}	
	return _default;
}
