
// Design a KDPoint class
//- Each class object represent a point in the N-Dimension space. 

#include <iostream>
#include <vector>
#include <algorithm>

#include "kdpoint.h"
#include "AddNumbers.h"

template<typename T, int nDimensions>
Point<T, nDimensions>::Point(): elements_() {}


template<typename T, int nDimensions>
void Point<T, nDimensions>::printPoint(){
    int i;
    std::cout<<"(";
    for(i=0; i<nDimensions-1; i++)
        std::cout<<elements_[i]<<",";
    std::cout<<elements_[i]<<")\n";
}


template< typename T, int nDimensions>
Point<T, nDimensions>::Point( int x, T arr[] )
{
    for(int i=0;i<x;i++)
        elements_[i] = arr[i];

}  

template< typename T, int nDimensions>
Point<T, nDimensions>::Point( T x, T y )
{

    elements_[0] = x;
    elements_[1] = y;
}

template< typename T, int nDimensions>
Point<T, nDimensions>::Point(T x, T y, T z )
{

    elements_[0] = x;
    elements_[1] = y;
    elements_[2] = z;
}
#if 0
template< typename T, int nDimensions>
T& Point<T, nDimensions>::operator[]( int const i )
{
    return elements_[i];
}
#endif

#if 0

   T& operator[]( int const i )
    {
        return elements_[i];
    }

    T const& operator[]( int const i ) const
    {
        return elements_[i];
    }

    void operator+=( Point const& other )
    {
        for( int i = 0; i < nDimensions; ++i )
        {
            elements_[i] += other.elements_[i];
        }
    }

    void operator-=( Point const& other )
    {
        for( int i = 0; i < nDimensions; ++i )
        {
            elements_[i] -= other.elements_[i];
        }
    }

    friend Point operator+( Point const& a, Point const& b )
    {
        Point ret( a );

        ret += b;
        return ret;
    }

    friend Point operator-( Point const&a, Point const& b )
    {
        Point ret( a );

        ret -= b;
        return ret;
    }


    Point(): elements_() {}
    Point( ValueType x, ValueType y )
    {

        elements_[0] = x;
        elements_[1] = y;
    }
    
    Point( T x, T y, T z )
    {

        elements_[0] = x;
        elements_[1] = y;
        elements_[2] = z;
    }       
    
    Point( int x, T arr[])
    {
        for(int i=0;i<x;i++)
            elements_[i] = arr[i];

    }    
#endif


AddNumbers::AddNumbers ()
: _a(0), _b(0)
{
}

AddNumbers::~AddNumbers ()
{
}

void AddNumbers::setA (int a)
{
        _a = a;
}

void AddNumbers::setB (int b)
{
        _b = b;
}

int AddNumbers::getA () const
{
        return _a;
}

int AddNumbers::getB () const
{
        return _b;
}

int AddNumbers::getSum () const
{
        return _a + _b;
}
