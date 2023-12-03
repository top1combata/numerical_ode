#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED

#include <array>
#include <iostream>


template <class T, size_t n>
struct Vec
{
public:

    Vec();
    template <class F>
    Vec(const std::initializer_list<F>&);

    Vec& operator+=(const Vec& vec);
    Vec& operator-=(const Vec& vec);

    template<class F>
    Vec& operator*=(F);

    Vec operator-() const;

    T& operator[](int);
    const T& operator[](int) const;

private:

    std::vector<T> m_vec;
};



template <class T, size_t n>
Vec<T,n>::Vec() : m_vec(n,0) {}


template <class T, size_t n>
template <class F>
Vec<T,n>::Vec(const std::initializer_list<F>& arr) : m_vec(n,0)
{
    std::copy(arr.begin(), arr.end(), m_vec.begin());
}


template <class T, size_t n>
Vec<T,n>& Vec<T,n>::operator+=(const Vec& vec)
{
    for (size_t i = 0; i < n; i++)
        m_vec[i] += vec[i];

    return *this;
}


template <class T, size_t n>
Vec<T,n>& Vec<T,n>::operator-=(const Vec& vec)
{
    for (size_t i = 0; i < n; i++)
        m_vec[i] -= vec[i];
        
    return *this;
}


template <class T, size_t n>
template <class F>
Vec<T,n>& Vec<T,n>::operator*=(F num)
{
    for (size_t i = 0; i < n; i++)
        m_vec[i] *= num;
        
    return *this;
}


template <class T, size_t n>
Vec<T,n> Vec<T,n>::operator-() const
{
    Vec res;
    return res -= *this;
}


template <class T, size_t n>
T& Vec<T,n>::operator[](int i)
{
    return m_vec[i];
}

template <class T, size_t n>
const T& Vec<T,n>::operator[](int i) const
{
    return m_vec[i];
}


template <class T, size_t n>
Vec<T,n> operator+(const Vec<T,n>& vec1, const Vec<T,n>& vec2)
{
    Vec<T,n> res(vec1);
    return res += vec2;
}


template <class T, size_t n>
Vec<T,n> operator-(const Vec<T,n>& vec1, const Vec<T,n>& vec2)
{
    Vec<T,n> res(vec1);
    return res -= vec2;
}


template <class T, class F, size_t n>
Vec<T,n> operator*(const Vec<T,n>& vec, F num)
{
    Vec<T,n> res(vec);
    return res *= num;
}


template <class T, class F, size_t n>
Vec<T,n> operator/(const Vec<T,n>& vec, F num)
{
    Vec<T,n> res(vec);
    return res *= 1/num;
}


template <class T, class F, size_t n>
Vec<T,n> operator*(F num, const Vec<T,n>& vec)
{
    Vec<T,n> res(vec);
    return res *= num;
}


template <class T, size_t n>
std::ostream& operator<<(std::ostream& os, const Vec<T,n>& vec)
{
    for (size_t i = 0; i < n; i++)
        os << vec[i] << ' ';
    return os;
}

#endif