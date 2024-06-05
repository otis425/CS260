#include <iostream>
#include "binarysearchtree.h"

void print_tree(BinarySearchTree& bst) {
    std::cout << "Tree : ";
    bst.inorderTraversal();
    std:: cout << " root = " << bst.root->data;
    std::cout << std::endl;
}

int main() {
    // create tree
    std::cout << "Create tree with root of 3 :" << std::endl;
    BinarySearchTree bst(3);
    print_tree(bst);
    // adding elements
    std::cout << "Add test :" << std::endl;
    std::cout <<" Add 5 " << std::endl;
    bst.add(5);
    print_tree(bst);
    std::cout <<" Add 1 " << std::endl;
    bst.add(1);
    print_tree(bst);
    std::cout <<" Add 7 " << std::endl;
    bst.add(7);
    print_tree(bst);
    std::cout <<" Add 2 " << std::endl;
    bst.add(2);
    print_tree(bst);
    std::cout <<" Add 9 " << std::endl;    
    bst.add(9);
    print_tree(bst);
    std::cout <<" Add 4 " << std::endl;
    bst.add(4);
    print_tree(bst);
    std::cout <<" Add 6 " << std::endl;
    bst.add(6);
    print_tree(bst);
    std::cout <<" Add 8 " << std::endl;
    bst.add(8);
    print_tree(bst);

    // removing elements
    std::cout << "Remove test :" << std::endl;
    std::cout <<" Remove 5 " << std::endl;
    bst.remove(4);
    print_tree(bst);
    std::cout <<" Remove 3 " << std::endl;
    bst.remove(3);
    print_tree(bst);
    std::cout <<" Remove 1 " << std::endl;
    bst.remove(1);
    print_tree(bst);

    // traversal
    std::cout << "Inorder traversal: ";
    bst.inorderTraversal();
    std::cout << std::endl;

    return 0;
}