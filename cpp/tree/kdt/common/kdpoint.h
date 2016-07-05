#ifndef KDPOINT_H_
#define KDPOINT_H_
/* http://stackoverflow.com/questions/11891192/c-templates-simple-point-class */
#include <array>
#include <type_traits>

template< typename T, int nDimensions =3 >
class Point
{
protected:
    std::array< T, nDimensions > elements_;
    
public:
    typedef T ValueType;
    
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


    bool operator>( Point const& other )
    {
        return elements_[0] > other.elements_[0];
    }

    bool operator<( Point const& other )
    {
        return elements_[0] < other.elements_[0];
    }    
    
    
    Point(): elements_() {}
    
    Point( T x, T y )
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
    void printPoint() {
        int i;
        std::cout<<"(";
        for(i=0; i<nDimensions-1; i++)
            std::cout<<elements_[i]<<",";
        std::cout<<elements_[i]<<")\n";
    }
    friend std::ostream& operator << (std::ostream& os, Point const&p)
    {
        int i;
        os <<  "(";
        for( i = 0; i < nDimensions-1; i++ )
        {
           os << p.elements_[i] << ", ";
        }
        
        os <<  p.elements_[i] << ") \n";
        
        return os;
    }
};






#endif // KDPOINT_H_
