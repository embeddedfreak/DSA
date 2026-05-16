/******************************************************************************
Problem:
Build a Binary Tree using preorder traversal array.

Rules:
- Each value represents a node.
- -1 represents NULL.

Example Input:
1 2 -1 -1 3 4 -1 -1 5 -1 -1

Constructed Tree:
        1
       / \
      2   3
         / \
        4   5

Algorithm:
1. Maintain an index variable globally/static.
2. Read elements one by one from preorder array.
3. Increment index in every recursive call.
4. If current element is -1:
      return NULL.
5. Create a new node using current value.
6. Recursively create left subtree.
7. Recursively create right subtree.
8. Return root node.
9. Traverse tree using preorder traversal to verify output.

Time Complexity:
O(n)

Space Complexity:
O(n)  // recursion stack
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

// Function to build binary tree recursively
Node* buildTree(vector<int> preorder)
{
    // Move to next element
    idx++;
    
    // If value is -1, return NULL node
    if(preorder[idx] == -1) {
        return NULL;
    }
    
    // Create new node
    Node* root = new Node(preorder[idx]);
    
    // Build left subtree
    root->left = buildTree(preorder);
    
    // Build right subtree
    root->right = buildTree(preorder);
    
    // Return root node
    return root;
}

// Preorder Traversal:
// Root -> Left -> Right
void preorder_traverse(Node* root) 
{
    // Base condition
    if(root == NULL) {
        return;
    }
    
    // Print current node
    cout<<root->data<<" ";
    
    // Traverse left subtree
    preorder_traverse(root->left);
    
    // Traverse right subtree
    preorder_traverse(root->right);
}

int main()
{
    // Preorder traversal array
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    
    // Build tree
    Node* root = buildTree(preorder);
    
    // Print preorder traversal
    preorder_traverse(root);
    
    return 0;
}
