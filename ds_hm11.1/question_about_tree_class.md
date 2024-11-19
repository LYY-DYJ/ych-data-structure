# Question about tree class #  
打扰老师了！我有疑问想要请教老师。我对树作为c++中的类有一点疑问。 
## 1 ##
上课讲的ppt中，定义两个类，一个树类，一个节点类，由树类维护由树节点组合成的树。如以下代码：
```cpp
class Node
{
private:
    friend class Tree;
    T value;
    Node* left;
    Node* right;
}

class Tree
{
public:
    Node* root;
    void preorder(Node* );
    ...
}
```
这没有体现树=根节点+子树，这个代码只能调用子树根节点，而不是子树，所以子树遍历也只能用原来的树的成员函数：
```cpp
Tree tree.preorder(tree.root->left);
```
## 2 ##
所以我考虑只定义一个树节点类，一个树节点就是一棵树：
```cpp
class Tree
{
private:
    T value;
    Tree* left;
    Tree* right;
public:
    void preorder();
}
```
那么就遇到了表示空树的问题。如果用```Tree* root = nullptr```,那就无法对其使用成员函数，因为空指针不能解引用,即使在成员函数开头挡住也不可以：
```cpp
void Tree::preorder()
{
    if(this==nullptr)
        return;
    visit(value);
    left->preorder();
    right->preorder();
}
```
这会产生警告，this不可以为空指针，即使在函数开头就判断来挡住。这个链接回答了这个问题：<https://stackoverflow.com/questions/48067323/c-why-cant-this-be-a-nullptr>  
即使在调用子树的方法前用判断挡住空指针也不行，因为根可能就是空的:
```cpp
void Tree::preorder()
{
    visit(value);//error
    if(left)
        left->preorder();
    if(right)
        right->preorder();
}
```
在树的外部判断树是否为空是一种办法，但是我不是很满意。因为空树也是树，应该树自己负责树。
## 3 ##
这里为了能够对空树使用方法，所以我就把方法都声明为静态的。
```cpp
class Tree
{
public:
    T value;
    Tree *left;
    Tree *right;
    static void preorder(Tree *root);
}
```
但是这样c++就退化了，退化成了c，类的方法成了有命名域的全局函数而不是和对象绑定。

所以我想请教老师，树作为类最好怎么写。