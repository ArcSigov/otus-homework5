#pragma once

#include <map>
#include "cell.h"


template <typename T>
class column{
public:
	 column(int _default = int());
	~column();
	 cell<T>& operator[](const int column);
     auto column_begin();
     auto column_end();
     auto column_begin() const;
     auto column_end()   const;
private:
     std::map<const int , cell<T>> _column{};
	 int def_value;
};


//!< конструктор новой ячейки матрицы
template <typename T>
cell<T>& column<T>::operator[](const int column)
{
	//!< если ячейка не была раннее создана, то создаем пару из мапы и ячейки
	auto it = _column.find(column);	
	if (it == _column.end())
	{
        cell<T> cell(def_value);
		bool b;
		std::tie(it,b) = _column.emplace(column,cell);
	}
	return it->second;
}

template <typename T>
column<T>::column(int _default): def_value(_default){};

template <typename T>
column<T>::~column(){}


template <typename T>
auto column<T>::column_begin()
{
    return _column.begin();
}

template <typename T>
auto column<T>::column_begin() const
{
    return _column.cbegin();
}

template <typename T>
auto column<T>::column_end()
{
    return _column.end();
}

template <typename T>
auto column<T>::column_end() const
{
    return _column.cend();
}
