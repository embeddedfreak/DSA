/******************************************************************************
Problem:
Build a Binary Tree from preorder traversal array
and perform postorder traversal.

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

Postorder Traversal:
Left -> Right -> Root

Expected Output:
2 4 5 3 1

Algorithm for Tree Construction:
1. Maintain a global/static index.
2. Increment index during recursive calls.
3. If current value is -1:
      return NULL.
4. Create node with current value.
5. Recursively build left subtree.
6. Recursively build right subtree.
7. Return root node.

Algorithm for Postorder Traversal:
1. Traverse left subtree.
2. Traverse right subtree.
3. Print current node.

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
    
    // If current value is -1, return NULL
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

// Postorder Traversal:
// Left -> Right -> Root
void postorder_traverse(Node* root) 
{
    // Base condition
    if(root == NULL) {
        return;
    }
    
    // Traverse left subtree
    postorder_traverse(root->left);
    
    // Traverse right subtree
    postorder_traverse(root->right);
    
    // Visit current node
    cout<<root->data<<" ";
}

int main()
{
    // Preorder traversal array
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    
    // Build binary tree
    Node* root = buildTree(preorder);
    
    // Print postorder traversal
    postorder_traverse(root);
    
    return 0;
}
