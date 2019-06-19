#pragma once
#include <tuple>
#include <map>
#include "matrix_iterator.hpp"



template<typename T, T def>
class physical_matrix 
{
    static constexpr T _default = def;
    using matrix_position = std::pair<std::size_t,std::size_t>;
public:
    physical_matrix(){};
    auto size () const  
    {
        return _matr.size();
    }
    auto& operator[](const std::size_t& pos)
    {
        pair.second = pos;
        return *this;
    }
    auto& operator = (const T& other)
    {
        if (other != _default)
        {
            _matr[pair] = other;
        }   
        else
        {
           if (_matr.find(pair) != _matr.end())
               _matr.erase(_matr.find(pair)->first);
        }
        return *this;
    }
    void set_row(const std::size_t& row)
    {
        pair.first = row; 
    }
    auto begin() 
    {
        return _matr.begin();
    };  
    auto end()  
    {
        return _matr.end();
    }

    auto get() const
    {
        auto it = _matr.find(pair);
        if (it != _matr.end())
            return it->second;
        return def;
    }
    operator auto()
    {
        return get();
    }
private:
    matrix_position pair;
    std::map<matrix_position,T> _matr{};
  };

//!< proxy of real matr
template<typename T, T def>
class matrix 
{
public: 
    explicit matrix(){};
    matrix operator = (const matrix& other) = delete;
    matrix (const matrix& other) = delete;

    auto size () const 
    {
        return real.size();
    }

    auto begin()  
    {
        return matrix_iterator<T>(real.begin());
    }

    auto end()  
    {
        return matrix_iterator<T>(real.end());
    }

    auto& operator [] (const std::size_t& row)
    {
        real.set_row(row);
        return real;
    }
private:
     physical_matrix<T,def> real;
};

