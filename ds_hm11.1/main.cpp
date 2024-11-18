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