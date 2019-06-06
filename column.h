#pragma once

#include <map>
#include "cell.h"



template <typename T>
class column{
public:
	 column(T _default =T());
	~column();
	 auto& operator[](const int column);
	 auto& operator = (const T& other);
	 bool operator ==(const T& other);
	 auto get_value() const;
	 auto size() const;
	 auto cell_size() const;
	 auto column_begin() const;
	 auto column_end() const;

private:
     std::map<const int , T> cell;
	 std::map <const int ,column<T>> _this;
	 T def_value;
};


template<typename T>
auto& column<T>::operator[](const int _column)
{
	auto it = _this.find(_column);	
	if (it == _this.end())
	{
        column<T> column(def_value);
		bool b;
		std::tie(it,b) = _this.emplace(std::make_pair(_column,column));
	}
	return it->second;
}

template <typename T>
column<T>::column(T _default):  def_value(_default){};

template <typename T>
column<T>::~column(){}

template <typename T>
auto& column<T>::operator = (const T& other)
{
	if (other != def_value)
		cell[0] = other;
	
	if (cell.size() && other == def_value)
		cell.erase(0);
	return *this;
}

template <typename T>
auto column<T>::size() const
{
	auto asize = 0;
	for (auto it = _this.begin(); it!=_this.end();it++)
	{
		asize += it->second.cell_size();

	}
	return asize;
}

template <typename T>
auto column<T>::get_value() const
{
	if (cell.size())
		return cell.at(0);
	return def_value;	
}

template <typename T>
auto column<T>::cell_size() const
{
	return cell.size();	
}


template <typename T>
bool column<T>::operator ==(const T& other)
{
	if (cell.size()!=0)
		return other == cell.at(0);
	
	return other == def_value;
}

template <typename T>
auto column<T>::column_begin() const
{
	return _this.cbegin();
}

template <typename T>
auto column<T>::column_end() const
{
	return _this.cend();
}