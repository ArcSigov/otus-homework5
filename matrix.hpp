#pragma once
#include <tuple>
#include <map>
#include "matrix_iterator.hpp"



template<typename T, T def>
class physical_matrix 
{
    static constexpr T _default = def;
    using matrix_position = std::pair<int,int>;
public:
    physical_matrix(){};
    auto size () const  
    {
        return _matr.size();
    }
    auto& operator[](const unsigned int pos)
    {
        pair.second = pos;
        return *this;
    }
    bool operator == (const T& other)
    {
        if (_matr.find(pair) != _matr.end())
            return _matr[pair] == other;
        return other == def;
    }
    auto& operator = (const T& other)
    {
        auto it = _matr.find(pair);
        if (other != _default)
        {
            _matr[pair] = other;
        }   
        else
        {
           if (it != _matr.end())
           {
                _matr.erase(it->first);
           }
        }
        return *this;
    }
    void set_row(const unsigned int& row)
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
        if (_matr.find(pair) != _matr.end())
            return _matr.at(pair);
        return def;
    }

    friend std::ostream& operator << (std::ostream &out, const physical_matrix<T,def> &phys)
    {
        out << phys.get();
        return out;
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

    auto& operator [] (const int& row)
    {
        real.set_row(row);
        return real;
    }
private:
     physical_matrix<T,def> real;
};

