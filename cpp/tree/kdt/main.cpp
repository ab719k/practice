#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

typedef std::vector<double> dVector_t;

//const int k=3;

// A structure to represent node of kd tree
//class Node{
//  std::vector<double> v[k]; // To store k dimensional point
//  Node *left, *right;
//};


template<class T>
class KDTreeNode {
  private:
    T* data;
    KDTreeNode<T>* parent;
    std::vector< KDTreeNode<T>* > children;
  public:
    KDTreeNode(KDTreeNode<T>* parent, T data);
    KDTreeNode(std::string FileName);
    void insert(int depth, T data);    
    ~KDTreeNode();
};



template<class T>
KDTreeNode<T>::KDTreeNode(KDTreeNode<T>* parent, T data) : parent(parent) {
}

template<class T>
KDTreeNode<T>::KDTreeNode(std::string FileName){

}


template<class T>
KDTreeNode<T>::~KDTreeNode() {  
  delete data;
  for(KDTreeNode<T>* childNode : children)
    delete childNode;
}



int main(int argc, char*argv[])
{
      double dValue;
      dVector_t myVector;
      std::vector<double> myPoint;
      std::string::size_type sz;
      long double value;                  
      std::ifstream  data("sample_data.csv");
      std::cout.precision(18);                      
      std::string line;
      KDTreeNode<double> MyKDTree("sample_data.csv");
      
      
      while(std::getline(data,line))
      {
        std::stringstream  lineStream(line);
        std::string        cell;
        while(std::getline(lineStream,cell,','))
        {
          std::cout<<"1 Value of the cell:"<< cell << "\n";
          //std::cout << "Length of Cell is " << cell.length()<<"\n"; 
          std::cout.precision(cell.length()-6);
          myVector.push_back(std::stold(cell,&sz));
          dValue = std::stold(cell,&sz);
          std::cout<<"2 Value of the cell:"<< std::scientific << dValue << "\n";
          myPoint.push_back(dValue);
        }

        //TO implement
        //MyKDTree.insert_node(myPoint);
        std::cin>> value;

      }
      std::ifstream myfile;
      myfile.open ("query_data.csv");
//      std::cout<<"Enter a key:";
//      std::cin >> value;
      myfile.close();
      std::cout << "Exiting \n";
      return 0;
}
