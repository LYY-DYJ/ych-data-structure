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
