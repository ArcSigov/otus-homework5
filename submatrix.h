#pragma once

#include <map>

template <typename T, int _default>
class submatrix{
	static constexpr int _def_value = _default;
public:
	 submatrix();
	~submatrix();
	 T& operator[](const int column);
	 void insert(const int column, const T& var);
	 void erase (const int column);

private:
	 std::map<const int , T> _submatrix{};
	 int def_value;
};


template <typename T, int _default>
T& submatrix<T,_default>::operator[](const int column)
{
	std::cout << def_value;
	auto it = _submatrix.find(column);
	if (it == _submatrix.end())
	{
		std::cout << "tut" << std::endl;
		return def_value;
	}
	std::cout << "ne_tut" << std::endl;
	return _submatrix[column];
}



template <typename T, int _default>
submatrix<T,_default>::submatrix():  def_value(_def_value)
{
}

template <typename T, int _default>
submatrix<T,_default>::~submatrix()
{

}

template <typename T, int _default>
void submatrix<T,_default>::erase(const int column)
{
	_submatrix.erase(column);
}

template <typename T, int _default>
void submatrix<T,_default>::insert(const int column, const T& var)
{
	if (var != def_value)
		_submatrix[column] = var;
}

