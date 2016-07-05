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
    
    void printPoint();
};




#if 0
typedef Point< int, 2 > Point2Di;
typedef Point< int, 3 > Point3Di;
typedef Point< int, 4 > Point4Di;
typedef Point< int, 5 > Point5Di;
typedef Point< int, 6 > Point6Di;

typedef Point< double, 2 > Point2Dd;
typedef Point< double, 3 > Point3Dd;
typedef Point< double, 4 > Point4Dd;
typedef Point< double, 5 > Point5Dd;
typedef Point< double, 6 > Point6Dd;

typedef Point< float, 2 > Point2Df;
typedef Point< float, 3 > Point3Df;
typedef Point< float, 4 > Point4Df;
typedef Point< float, 5 > Point5Df;
typedef Point< float, 6 > Point6Df;
#endif


#endif // KDPOINT_H_