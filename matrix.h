#pragma once

#include <map>
#include "column.h"
#include <tuple>
#include <memory>

template <typename T, int def_val>
class matrix  {
	static constexpr int _default = def_val;
	using iter = typename std::map<const int,column<T>>::iterator;
	using citer = typename std::map<const int,column<T>&>::const_iterator;

public:

	
	 matrix();
	 matrix(const matrix&&) = delete;
	~matrix();
	

	// template <typename auto>
	// class matrix_iterator 
	// {
	// 	public:
    // 		matrix_iterator(auto &it)
	// 		{
	// 			this->row_ptr = it;
	// 		};

    // 		bool operator!=(matrix_iterator<U>& other) 
	// 		{
	// 			return this->row_ptr != other.row_ptr;
	// 		}

    // 		bool operator==(matrix_iterator<U>&  other) 
	// 		{
	// 			return this->row_ptr == other.row_ptr;
	// 		}

    // 		auto operator*() 
	// 		{
	// 			// auto row_num = this->row_ptr->first;
	// 			// auto column_num = this->row_ptr->second.column_begin().first;
	// 			// auto cell_value  = column_num.second.cell_value();
	// 			// auto result = std::make_tuple<row_num,column_num,cell_value>;				
	// 			// return result;
	// 			return *row_ptr;
	// 		}

    // 		auto operator++() const
	// 		{
	// 			row_ptr++;
	// 			return *this;
	// 		}
	// 	private:
	// 		 auto row_ptr;
	// };

	

	// matrix_iterator <iter> begin()
	// {
	// 	 matrix_iterator<iter> (_matrix.begin());
	// };
	// matrix_iterator <iter> end()
	// {
	// 	return matrix_iterator<iter>(_matrix.end());
	// };
	//const matrix_iterator cbegin();
	//const matrix_iterator cend();

	column<T>& operator[](const int row);
	std::size_t size();
private:
	std::map<const int,column<T>> _matrix{};
};


template <typename T, int def_val>
matrix<T,def_val>::matrix(){}

template <typename T, int def_val>
matrix<T,def_val>::~matrix(){}



template <typename T, int def_val>
std::size_t matrix<T,def_val>::size()
{
	 auto asize = 0;
	 for (auto it = _matrix.cbegin() ; it != _matrix.cend(); ++it)
	 {
		for (auto it1 = it->second.column_begin(); it1 != it->second.column_end(); ++it1)
		{
			asize += it1->second.cell_size();
		}		
	 }
	return asize;
}

//!<конструирует на месте новую строку матрицы и возвращает ее пользователю
template <typename T, int def_val>
column<T>& matrix<T,def_val>::operator[](const int row)
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