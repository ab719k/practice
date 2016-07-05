#ifndef NODE_H_
#define NODE_H_


template< typename T>
class node {
    private:
        int dimension; // what is the dimension choosen at this level
        T *data; // Partition_node or Leaf_node: Reference to the object
        node *left, *right;
        node *parent;
        int depth;
    public:
        node(int k,  T arr[]) {
            left=right=parent=null;
            data=new T;
            data=T;
        }
        node *left_child() {
            return left;
        }
        node *right_child() {
            return right;
        }
        node *parent() {
            return parent;
        }
        int current_dimension() {
            return dimension;
        }  
        int current_depth() {
            return dimension;
        }
        void left_child(node *l) {
            left=l;
        }
        void right_child(node *r) {
            right=r;
        }
        void parent(node *p) {
            parent=p;
        }
        void set_current_dimension(int d) {
            dimension=d;
        }  
        void set_current_depth(int d) {
            depth=d;
        }     
}



#endif // NODE_H_

