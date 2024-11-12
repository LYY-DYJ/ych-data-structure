#include<List.h>

template <class T>
class BinaryTree
{
private:
    T* value;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
public:
    BinaryTree();
    ~BinaryTree();
    void delete_tree();
    static void pre_inorder_create(List<T> preoder,List<T> inorder);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    value = new T;
    left=nullptr;
    right=nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    delete_tree();
}

template <class T>
void BinaryTree<T>::delete_tree()
{
    if(left)
        left->delete_tree();
    if(right)
        right->delete_tree();
    delete value;
}
