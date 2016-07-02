
// Design a KDPoint class
//- Each class object represent a point in the N-Dimension space. 

#include <iostream>
#include <vector>
#include <algorithm>

#include "KDPoint.hpp"

template< typename T, int nDimensions>
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
Point<T, nDimensions>::Point( ValueType x, ValueType y )
{

    elements_[0] = x;
    elements_[1] = y;
}

template< typename T, int nDimensions>
Point<T, nDimensions>::Point( ValueType x, ValueType y, ValueType z )
{

    elements_[0] = x;
    elements_[1] = y;
    elements_[2] = z;
}