#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "kdpoint.h"

const int MAX_DIMENSION = 3;


typedef std::vector<double> dVector_t;



int main(int argc, char*argv[])
{
    if (!(argc == 2)) {
        std::cout<<"usage build_kdtree <filename>\n";
    }
    double dValue;
    
    Point<double, MAX_DIMENSION> vNode;

    std::vector<Point<double, MAX_DIMENSION>> vSet;
    
    
    /* File I/O */
    std::ifstream  fdata(argv[1]);
    std::string line;
    std::string::size_type sz;
    
    int i=0;
    int max_per_dim[MAX_DIMENSION];
    
    int min_per_dim[MAX_DIMENSION];
    
    /* Reset all values */
    for(i=0;i<MAX_DIMENSION;i++) {
        max_per_dim[i]=0;
        min_per_dim[i]=0;
    }
    
    /* Read first line */
    while(std::getline(fdata,line))
    {
        std::stringstream  lineStream(line);
        std::string        cell;
        //std::cout<<linenum<<":";
        i=0;
        while(std::getline(lineStream,cell,','))
        {
            //std::cout<<"Value of the cell:"<< cell << "\n";
            //std::cout << "Length of Cell is " << cell.length()<<"\n"; 
            //std::cout.precision(cell.length()-6);
            //myVector.push_back(std::stold(cell,&sz));
            dValue = std::stold(cell,&sz);
            //std::cout<< std::scientific << dValue << "\t";
            max_per_dim[i] = max_per_dim[i]<dValue?dValue:max_per_dim[i];
            min_per_dim[i] = min_per_dim[i]>dValue?dValue:min_per_dim[i];
            vNode[i++]=dValue;
        }
        vSet.push_back(vNode);
        //std::cout<<"\n";
        //TO implement
        //MyKDTree.insert_node(vNode);
        //std::cin>> value;
        //linenum++;
        //if(linenum %1000 == 0) {
          //std::cin>> value;
        //}
        
    }
    
 i=1;   
 for (std::vector<Point<double, MAX_DIMENSION>>::const_iterator itr = vSet.begin(); itr != vSet.end(); ++itr) {
    std::cout.precision(18);
    std::cout << i++ << ":" << std::scientific << *itr << ' ';   
 }
}


















#if 0   
//typedef Point<double,3> Pt3d;

int main(int argc, char*argv[])
{
    std::cout << "starting\n";
    
    //double a[3]= {3.812286312667677590e-01,2.249309626074655899e-01,5.286729037289117361e-01};
    Point<int, 3>  a( 1, 2, 3 );
    Point<int, 3>  b( 4, 5, 6 );
    
    std::cout << "Declaring Pt3d" << std::endl;

    Point<double, 3>  B3d(3.812286312667677590e-01,2.249309626074655899e-01,5.286729037289117361e-01);
    //Point3Dd A3d(3,&a[0]);
    
    B3d.printPoint();
    std::cout << "Declaried Pt3d" << std::endl;
    
    //A3d.printPoint();

}


 
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

