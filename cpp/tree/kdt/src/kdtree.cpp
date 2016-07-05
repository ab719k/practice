#include iostream

template< typename P>
kdtree<P>::kdtree(std::string fname)
{
    P dValue;
    
    std::vector<P> myPoint;
    std::string::size_type sz;
    P value;                  
    std::ifstream  data(fname);
    std::cout.precision(PRECISION_COUNT);                      
    std::string line;
    long int linenum=0;      

    if (fname.size()==0) {
        std::cerr<<"No File present";
        throw "blank file error"
    } 

    while(std::getline(data,line))
    {
    std::stringstream  lineStream(line);
    std::string        cell;
    std::cout<<linenum<<":";
    while(std::getline(lineStream,cell,','))
    {
      //std::cout<<"Value of the cell:"<< cell << "\n";
      //std::cout << "Length of Cell is " << cell.length()<<"\n"; 
      std::cout.precision(cell.length()-6);
      myVector.push_back(std::stold(cell,&sz));
      dValue = std::stold(cell,&sz);
      std::cout<< std::scientific << dValue << "\t";
      myPoint.push_back(dValue);
    }
    std::cout<<"\n";
    //TO implement
    //MyKDTree.insert_node(myPoint);
    //std::cin>> value;
    linenum++;
    //if(linenum %1000 == 0) {
      //std::cin>> value;
    //}
    }

exit_KDTreeNode1:
  linenum=0;

}