#include <iostream>
#include<vector>

using namespace std;

// Node class for Binary Tree
class Node {
public: 
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize node data
    // and set left/right child as NULL
    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

// Function to build Binary Tree using preorder traversal
// preorder format:
// Node -> Left -> Right
// -1 represents NULL node
Node* buildTree(vector<int> preorder, int &idx) 
{
    // Move to next element in preorder array
    idx++;    
    
    // Base condition:
    // If index goes out of bounds
    // OR current node is -1
    // return NULL
    if(idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }
    
    // Create new node using current preorder value
    Node* root = new Node(preorder[idx]);
    
    // Recursively create left subtree
    root->left = buildTree(preorder, idx);
    
    // Recursively create right subtree
    root->right = buildTree(preorder, idx);
    
    // Return root node
    return root;
}

// Algorithm:
// Step 1: Check if the current node is NULL
//         - If yes, return 0 because there are no nodes.
//
// Step 2: Recursively count nodes in the left subtree
//         - Store result in leftCount.
//
// Step 3: Recursively count nodes in the right subtree
//         - Store result in rightCount.
//
// Step 4: Add:
//         - left subtree node count
//         - right subtree node count
//         - 1 for current node
//
// Step 5: Return total count.

int countNodes(Node* root) 
{
    // Base condition
    if(root == NULL) {
        return 0;
    }
    
    // Count nodes in left subtree
    int leftCount = countNodes(root->left);
    
    // Count nodes in right subtree
    int rightCount = countNodes(root->right);
    
    // Return total nodes
    return (leftCount + rightCount + 1);
}

int main()
{
    // Index variable for preorder traversal
    int idx = -1;
    
    // Preorder traversal input
    // -1 indicates NULL node
    vector<int> preorder = { 
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };

    // Build Binary Tree
    Node* root = buildTree(preorder, idx);
    
    // Print height of tree
    cout<<"Height of this tree is: "<<countNodes(root)<<endl;
    
    return 0;
}
