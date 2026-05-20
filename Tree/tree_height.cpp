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

// Function to calculate height of Binary Tree
int height(Node* root) 
{
    // Base condition:
    // Height of empty tree is 0
    if(root == NULL) {
        return 0;
    }    
    
    // Calculate height of left subtree
    int left_height = height(root->left);
    
    // Calculate height of right subtree
    int right_height = height(root->right);
    
    // Return maximum height + 1 for current node
    return (max(left_height, right_height) + 1);
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
    cout<<"Height of this tree is: "<<height(root)<<endl;
    
    return 0;
}
