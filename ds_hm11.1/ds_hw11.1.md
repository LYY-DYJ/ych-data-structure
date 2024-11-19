# DS_HW_11.1 #
## 实现 ##
### BinaryTree.h ###
前序遍历是preorder_print,中序遍历是inorder_print,后序遍历是postorder_print，从前序遍历和中序遍历生成二叉树是create_from_preorder_inorder
将所有空节点nullptr换成("#",nullptr,nullptr)，是extend,将除空树以外的空节点如此替换是dumb_extend
```cpp
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
```
## 测试 ##
先测试空树的两种extend，再通过循环测试不同树的通过前序和中序遍历创建,并分别三种方式遍历和扩展后遍历。
```cpp
#include <string.h>
#include "BinaryTree.h"

int main()
{
    char preorder[100], inorder[100];
    BinaryTree<char> *root = nullptr;
    BinaryTree<char>::extend(root);
    printf("preorder:");
    BinaryTree<char>::preorder_print(root);
    printf("\ninorder:");
    BinaryTree<char>::inorder_print(root);
    printf("\npostorder:");
    BinaryTree<char>::postorder_print(root);
    printf("\n\n");
    root = nullptr;
    BinaryTree<char>::dumb_extend(root);
    printf("preorder:");
    BinaryTree<char>::preorder_print(root);
    printf("\ninorder:");
    BinaryTree<char>::inorder_print(root);
    printf("\npostorder:");
    BinaryTree<char>::postorder_print(root);
    printf("\n\n");
    while (scanf("%s", preorder) && scanf("%s", inorder))
    {
        BinaryTree<char> *root = BinaryTree<char>::create_from_preorder_inorder(List<char>(strlen(preorder), preorder), List<char>(strlen(inorder), inorder));
        printf("preorder:");
        BinaryTree<char>::preorder_print(root);
        printf("\ninorder:");
        BinaryTree<char>::inorder_print(root);
        printf("\npostorder:");
        BinaryTree<char>::postorder_print(root);
        printf("\n");
        BinaryTree<char>::extend(root);
        printf("preorder:");
        BinaryTree<char>::preorder_print(root);
        printf("\ninorder:");
        BinaryTree<char>::inorder_print(root);
        printf("\npostorder:");
        BinaryTree<char>::postorder_print(root);
        printf("\n\n");
    }
    return 0;
}
```
## 结果 ##
![alt text](image.png)
