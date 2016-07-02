#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "KDPoint.hpp"
//#include "KDTree.hpp"

using namespace std;

//typedef Point<double,3> Pt3d;

int main(int argc, char*argv[])
{
    cout << "starting" << endl;
    
    double a[3]= {3.812286312667677590e-01,2.249309626074655899e-01,5.286729037289117361e-01};
    
    cout << "Declaring Pt3d" << endl;

    Point3Dd B3d(3.812286312667677590e-01,2.249309626074655899e-01,5.286729037289117361e-01);
    //Point3Dd A3d(3,&a[0]);
    
    //A3d.printPoint();

}


#if 0    
int main(int argc, char*argv[])
{
    
    double a[3]= {3.812286312667677590e-01,2.249309626074655899e-01,5.286729037289117361e-01};
    std::string line="5.476712170304818272e-01,3.931511472213524705e-01,4.671973542490692743e-02";
    KDPoint<double,3> X(3, &a[0]);
    KDPoint<double,3> Y(line);
    
    
    X.print();
    Y.print();
}

using namespace std;


ostream& operator<<( ostream& stream, Point3Di const& point )
{
    return (stream << "(" << point[0] << ", " << point[1] << ", " << point[2] << ")");
}


int main()
{
    cout << "starting" << endl;
    Point3Di a( 1, 2, 3 );
    Point3Di b( 4, 5, 6 );

    a += b;
    cout << a << endl;
    cout << "Exiting" << endl;
    return 0;
}
#endif

