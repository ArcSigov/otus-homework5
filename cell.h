#pragma once

#include <map>

template <typename T>
class cell{
public:
	 cell(int _default = int());
	~cell();
	 void operator=(const T& other);
	 bool operator==(const T other);
	 std::size_t cell_size() const;
	 std::size_t cell_size();
	 const T& cell_value() const;
	 T& cell_value();
private:
	 std::map<const int, T> _cell{};
	 int def_value;
};


template <typename T>
void cell<T>::operator=(const T& other)
{

	auto it = _cell.find(0);
	if (other != def_value)
	{
		if (it == _cell.end())
		{
			_cell.emplace(0,other);
		}
		else 
		{
			if (_cell[0] != other)
				_cell[0] = other;
		}
	}
	else
	{
		if (it != _cell.end())
			_cell.erase(0);
	}
}

template <typename T>
bool cell<T>::operator==(const T other)
{
	auto it = _cell.find(0);
	if (it==_cell.end() && other == def_value)
	{
		return true;
	}
	else
	{
		if (_cell[0] == other)
			return true;
	}
	return false;
}


template <typename T>
cell<T>::cell(int _default): def_value(_default){};

template <typename T>
cell<T>::~cell(){}

template <typename T>
std::size_t cell<T>::cell_size() const
{
	return _cell.size();
}

template <typename T>
std::size_t cell<T>::cell_size()
{
	return _cell.size();
}

template <typename T>
const T& cell<T>::cell_value() const
{
	auto it = _cell.find(0);
	if (it == _cell.end())
		return def_value;
	return _cell[0];
}

template <typename T>
T& cell<T>::cell_value()
{
	auto it = _cell.find(0);
	if (it == _cell.end())
		return def_value;
	return _cell[0];
}