#pragma once

#include <map>
#include "column.h"
#include <tuple>
#include <memory>


template <typename T>
class matrix_iterator
{
public:
	 matrix_iterator(typename std::map<const int,column<T>>::iterator iteratr);
	~matrix_iterator();
	
	 bool operator!=(matrix_iterator<T> const& other) const{
		 return _it != other._it;
	 };
     bool operator==(matrix_iterator<T> const& other) const{
		 return _it == other._it;
	 }; 
     
	 auto operator*() const
	 {
		return std::make_tuple(_row,_column,value);
	 }
     
	 auto operator++()
	 {
		 auto asize = 0;
		 auto col_start = _it->second.column_begin();
		 
		 col_start->second.cell_value();
		//  static auto it1 = _it->second.column_begin();
		//  if (it1 !=_it->second.column_end() && it1->second.cell_size() != 0) //!< если существует строка
		//  {
		// 	this->_row    = _it->first;
		// 	this->_column = it1->first;
		// 	this->value   = it1->second.cell_value();
		// 	it1++;
		// 	std::cout << "tut" << std::endl;
		//  }
		//  else
		//  {
		// 	 _it++;
		// 	 it1 = _it->second.column_begin();
		// 	 std::cout << "utut" << std::endl;
		//  }
		 return *this;
	 };

private:
	typename std::map<const int,column<T>>::iterator _it;
	int _row;
	int _column;
	T   value;
};

template<typename T>
matrix_iterator<T>::matrix_iterator(typename std::map<const int,column<T>>::iterator iteratr) : _it(iteratr), _row(0), _column(0),value(0) {};

template<typename T>
matrix_iterator<T>::~matrix_iterator(){};


template <typename T, int def_val>
class matrix  {
	static constexpr int _default = def_val;
public:

	
	 matrix();
	 matrix(const matrix&&) = delete;
	~matrix();

	 matrix_iterator<T> begin()
	 {
		 auto ttt = _matrix.begin();
		 while (ttt!= _matrix.end())
		 {
			 auto sss = ttt->second.column_begin();
			 

			 while (sss!= ttt->second.column_end())
			 {
				 std::cout << " beg=" << ttt->first ;
			 	 std::cout << " col=" << sss->first;
				 std::cout << " val=" << sss->second.cell_value();
				 std::cout <<std::endl;
				 sss++;
			 }
			 std::cout <<std::endl;
			 ttt++;
		 }
		
	 	 return matrix_iterator<T>(_matrix.begin());
	 }
	 matrix_iterator<T> end()
	 {
	 	 return matrix_iterator<T>(_matrix.end());
	 }

	column<T>& operator[](const int row);
	std::size_t size() const;
private:
	std::map<const int, column<T>> _matrix{};
};


template <typename T, int def_val>
matrix<T,def_val>::matrix(){}

template <typename T, int def_val>
matrix<T,def_val>::~matrix(){}



template <typename T, int def_val>
std::size_t matrix<T,def_val>::size() const
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