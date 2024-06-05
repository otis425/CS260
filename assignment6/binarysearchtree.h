#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    // constructor creates node with argument data for value
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// binary search tree struct
struct BinarySearchTree {
    Node* root;
    
    // constructor creates node with argument data for value at root
    BinarySearchTree(int value) {
        root = new Node(value);
        root->left = nullptr;
        root->right = nullptr;
    }

    // add new node with value, in the correct position
    void add(int value) {
        Node* newNode = new Node(value);

        Node* current = root;
        while (true) {
            if (value < current->data) {  // if value is less go left
                // if left is null, add new node
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                // if left exists, travel down it
                current = current->left;
            } else { // if value is greater or equal go right
                // if right is null, add new node
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                // if right exists, travel down it
                current = current->right;
            }
        }
    }

    // begin removal search from top of tree for value
    void remove(int value) {
        root = removeNode(root, value);
    }

    // removes the node with value from the tree rooted at node, returns the new root of current subtree
    Node* removeNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = removeNode(node->left, value); // continue down left subtree
        } else if (value > node->data) {
            node->right = removeNode(node->right, value); // continue down right subtree
        } else {
            if (node->left == nullptr) { // if no left child
                Node* temp = node->right; // save the right child
                delete node; // delete node
                return temp; // return right child as root
            } else if (node->right == nullptr) { // if the node has no right child
                Node* temp = node->left; // save the left child
                delete node; // delete the node
                return temp; // return the left child as the new root of the subtree
            }

            // if the node has two children
            Node* temp = node->right; 
            while (temp->left != nullptr) { // find least/leftmost node
                temp = temp->left;
            }
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }

        return node; // return the node as the default case
    }

    void inorderTraversal() {
        nodeinorderTraversal(root);
    }

    // inorder traversal function
    void nodeinorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        nodeinorderTraversal(node->left); // traverse left subtree
        std::cout << node->data << " "; // print current node
        nodeinorderTraversal(node->right); // traverse right subtree
    }
};

