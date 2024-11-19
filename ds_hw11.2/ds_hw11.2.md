# DS_HW_11.2 #
## 1~3 ##
![alt text](image-1.png)
## 4 ##
### 实现 ###
```a==b```包含了两者都为空的情况，也包含了一个树是另一个树的浅拷贝的情况，这是偶然聚集。
```cpp
template <class T>
bool BinaryTree<T>::compare(BinaryTree<T>* a,BinaryTree<T>* b)
{
    if(a==b)
        return 1;
    if((a==nullptr&&b!=nullptr)||(a!=nullptr&&b==nullptr))
        return 0;
    return (a->value==b->value)&&(compare(a->left,b->left))&&(compare(a->right,b->right));
}
```
### 测试 ###
```cpp
#include "BinaryTree.h"
#include "string.h"

int main()
{
    char preorder1[100], inorder1[100], preorder2[100], inorder2[100];
    while (scanf("%s", preorder1) && scanf("%s", inorder1)&&scanf("%s", preorder2) && scanf("%s", inorder2))
    {
        BinaryTree<char> *root1 = BinaryTree<char>::create_from_preorder_inorder(List<char>(strlen(preorder1), preorder1), List<char>(strlen(inorder1), inorder1));
        BinaryTree<char> *root2 = BinaryTree<char>::create_from_preorder_inorder(List<char>(strlen(preorder2), preorder2), List<char>(strlen(inorder2), inorder2));
        printf("%d\n", BinaryTree<char>::compare(root1, root2));
    }
}
```
### 结果 ###
![alt text](image.png)

因为在最坏情况下每个节点都只需要访问一次，所以复杂度为$O(n)$