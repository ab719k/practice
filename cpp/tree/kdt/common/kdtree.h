#ifndef _AB_KD_TREE_H
#define _AB_KD_TREE_H

#include <vector>
#include <memory>
#include <numeric>
#include <iostream>

const int PRECISION_COUNT 18;

// A structure to represent node of kd tree
class kNode
{
    private:
    
        int dimension; // To store k dimensional point
        int partition_value;
        kNode *left, *right;
        kNode *parent;
        vector<Point<T, nDimension>>& valref; //refernce to the vector of the k-dimension
        int depth;
    public:
    
        // A method to create a node of K D tree
        kNode(int d, int p, kNode *parent)
        {
            parent = null;
            dimension=d;
            depth=node_depth;
            partition_value=p;
                
            temp->left = temp->right = NULL;
            return temp;
        }
        kNode(kNode *p,int d, vector<Point<T, nDimension>>& v)
        {
            parent = p;
            depth=d;
            valref=v;
            temp->left = temp->right = NULL;
            return temp;
        }
    
    
        set_left_child(kNode *l) {
            left=l;
        }
        get_left_child(kNode *l) {
            left=l;
        }
    
        set_right_child(kNode *l) {
            left=l;
        }
        get_right_child(kNode *l) {
            left=l;
        }
    
    
        // Inserts a new node and returns root of modified tree
    // The parameter depth is used to decide axis of comparison
    void insertRec(Node *root, vector<Point<T, nDimension>>& v, unsigned depth)
    {
        // Tree is empty?
        if (root == NULL)
           return newNode(point);

        // Calculate current dimension (cd) of comparison
        unsigned cd = depth % k;

        // Compare the new point with root on current dimension 'cd'
        // and decide the left or right subtree
        if (point[cd] < (root->point[cd]))
            root->left  = insertRec(root->left, point, depth + 1);
        else
            root->right = insertRec(root->right, point, depth + 1);

        return root;
    }
    
    // Function to insert a new point with given point in
    // KD Tree and return new root. It mainly uses above recursive
    // function "insertRec()"
    Node* insertleaf(Node *root, int point[])
    {
        return insertRec(root, point, 0);
    }



};

struct leaf
{
    vector<Point<T, nDimension>>& v; //refernce to the vector of the k-dimension
    Node *parent;
};

template< typename T, int nDimension>
class kdtree {
    private:
        vector<T> vlist; // leaf node list
        vector<T> plist; // partition list
       
        
    public:
        kdtree() {}
        kdtree(vector<Point<T, nDimension>>) {
            
        
        }
}
    
#endif //_AB_KD_TREE_H