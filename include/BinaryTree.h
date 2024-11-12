#include <iostream>
#include "List.h"

template <class T>
class BinaryTree
{
public:
    T value;
    BinaryTree<T> *left;
    BinaryTree<T> *right;
    BinaryTree();
    void preorder_print();
    void inorder_print();
    void postorder_print();
    int leaf_num();
    int height();
    void mirror();
    static BinaryTree<T> *create_from_preorder_inorder(List<T> preorder, List<T> inorder);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    left = nullptr;
    right = nullptr;
}

template <class T>
void BinaryTree<T>::preorder_print()
{
    std::cout<<value<<" ";
    if(left!=nullptr)
        left->preorder_print();
    if(right!=nullptr)
        right->preorder_print();
}

template <class T>
int BinaryTree<T>::leaf_num()
{
    if (left == nullptr && right == nullptr)
        return 1;
    else if (left == nullptr)
        return right->leaf_num();
    else if (right == nullptr)
        return left->leaf_num();
    else
        return left->leaf_num() + right->leaf_num();
}

template <class T>
int BinaryTree<T>::height()
{
    if (left == nullptr && right == nullptr)
        return 1;
    else if (left == nullptr)
        return right->height() + 1;
    else if (right == nullptr)
        return left->height() + 1;
    else
    {
        int l_h = left->height();
        int r_h = right->height();
        return (l_h > r_h ? l_h : r_h) + 1;
    }
}

template <class T>
void BinaryTree<T>::mirror()
{
    if(left!=nullptr)
        left->mirror();
    if(right!=nullptr)
        right->mirror();
    BinaryTree<T>* temp;
    temp=left;
    left=right;
    right=temp;
}

template <class T>
BinaryTree<T> *BinaryTree<T>::create_from_preorder_inorder(List<T> preorder, List<T> inorder)
{
    BinaryTree<T> *root;
    if (preorder.length() == 0 || inorder.length() == 0)
        return nullptr;
    root = new BinaryTree<T>;
    preorder.get_value(0, root->value);
    int root_pos;
    inorder.find_value(root_pos, root->value);
    List<T> left_inorder;
    for (int i = 0; i < root_pos; i++)
        left_inorder.append(inorder[i]);
    List<T> right_inorder;
    for (int i = root_pos + 1; i < inorder.length(); i++)
        right_inorder.append(inorder[i]);
    List<T> left_preorder;
    for (int i = 1; i < root_pos + 1; i++)
        left_preorder.append(preorder[i]);
    List<T> right_preorder;
    for (int i = root_pos + 1; i < preorder.length(); i++)
        right_preorder.append(preorder[i]);
    root->left = create_from_preorder_inorder(left_preorder, left_inorder);
    root->right = create_from_preorder_inorder(right_preorder, right_inorder);
    return root;
}
