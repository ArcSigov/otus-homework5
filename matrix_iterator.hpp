#pragma once 


#include <tuple>
#include <map>

template <typename T>
class matrix_iterator
{
	using  output_matrix_iterator = typename std::map<std::pair<int,int>,T>::iterator;
public:
	 matrix_iterator(output_matrix_iterator iteratr);
	~matrix_iterator();
	 bool operator!=(matrix_iterator<T> const& other) const;
     bool operator==(matrix_iterator<T> const& other) const;
	 auto operator*() const;
	 auto operator++();
private:
	output_matrix_iterator iterator;
};


template<typename T>
matrix_iterator<T>::matrix_iterator(output_matrix_iterator iteratr) : iterator(iteratr) {}

template<typename T>
matrix_iterator<T>::~matrix_iterator(){}

template<typename T>
bool matrix_iterator<T>::operator != (matrix_iterator<T> const& other) const
{
    return iterator != other.iterator;
}

template<typename T>
bool matrix_iterator<T>::operator==(matrix_iterator<T> const& other) const
{
	return iterator == other.iterator;
}

template<typename T>
auto matrix_iterator<T>::operator*() const
{
    return std::make_tuple(iterator->first.first,iterator->first.second,iterator->second);
}

template<typename T>
auto matrix_iterator<T>::operator++()
{
    iterator++;
    return *this;
}