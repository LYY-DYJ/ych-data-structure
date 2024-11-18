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
    static void preorder_print(BinaryTree<T> *root);
    static void inorder_print(BinaryTree<T> *root);
    static void postorder_print(BinaryTree<T> *root);
    static int leaf_num(BinaryTree<T> *root);
    static int height(BinaryTree<T> *root);
    static void mirror(BinaryTree<T> *root);
    static void extend(BinaryTree<T> *&root);
    static void dumb_extend(BinaryTree<T> *&root);
    static BinaryTree<T> *create_from_preorder_inorder(List<T> preorder, List<T> inorder);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    left = nullptr;
    right = nullptr;
}

template <class T>
void BinaryTree<T>::preorder_print(BinaryTree<T> *root)
{
    if (root == nullptr)
        return;
    std::cout << root->value << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}

template <class T>
void BinaryTree<T>::inorder_print(BinaryTree<T> *root)
{
    if (root == nullptr)
        return;
    inorder_print(root->left);
    std::cout << root->value << " ";
    inorder_print(root->right);
}

template <class T>
void BinaryTree<T>::postorder_print(BinaryTree<T> *root)
{
    if (root == nullptr)
        return;
    postorder_print(root->left);
    postorder_print(root->right);
    std::cout << root->value << " ";
}

template <class T>
int BinaryTree<T>::leaf_num(BinaryTree<T> *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return leaf_num(root->left) + leaf_num(root->right);
}

template <class T>
int BinaryTree<T>::height(BinaryTree<T> *root)
{
    if (root == nullptr)
        return 0;
    int l_h = height(root->left);
    int r_h = height(root->right);
    return (l_h > r_h ? l_h : r_h) + 1;
}

template <class T>
void BinaryTree<T>::mirror(BinaryTree<T> *root)
{
    if(root==nullptr)
        return;
    mirror(root->left);
    mirror(root->right);
    BinaryTree<T> *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
template <class T>
void BinaryTree<T>::extend(BinaryTree<T> *&root)
{
    if(root==nullptr)
    {
        root = new BinaryTree;
        root->value='#';
        return;
    }
    extend(root->left);
    extend(root->right);
}

template <class T>
void BinaryTree<T>::dumb_extend(BinaryTree<T> *&root)
{
    if(root==nullptr)
        return;
    if(root->left==nullptr)
    {
        root->left = new BinaryTree;
        root->left->value='#';
        return;
    }
    if(root->right==nullptr)
    {
        root->right = new BinaryTree;
        root->right->value='#';
        return;
    }
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
