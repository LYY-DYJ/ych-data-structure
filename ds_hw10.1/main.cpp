#include <stdio.h>
#include "BinaryTree.h"
#include "List.h"

int main()
{
    char pre[] = {'A', 'B', 'D', 'C', 'E', 'G', 'F', 'H', 'I'};
    List<char> preorder(9, pre);
    char in[] = {'D', 'B', 'A', 'E', 'G', 'C', 'H', 'F', 'I'};
    List<char> inorder(9, in);
    BinaryTree<char> *root = BinaryTree<char>::create_from_preorder_inorder(preorder, inorder);
    printf("%d %d\n",BinaryTree<char>::leaf_num(root),BinaryTree<char>::height(root));
    BinaryTree<char>::preorder_print(root);
    printf("\n");
    BinaryTree<char>::mirror(root);
    BinaryTree<char>::preorder_print(root);
    printf("\n");
    return 0;
}