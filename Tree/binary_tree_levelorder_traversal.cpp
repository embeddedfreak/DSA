/******************************************************************************
Problem:
Build a Binary Tree from preorder traversal array
and perform level order traversal.

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

Level Order Traversal:
Level by level from left to right.

Expected Output:
1 2 3 4 5

Algorithm for Tree Construction:
1. Maintain a global/static index.
2. Increment index during recursive calls.
3. If current value is -1:
      return NULL.
4. Create node with current value.
5. Recursively build left subtree.
6. Recursively build right subtree.
7. Return root node.

Algorithm for Level Order Traversal:
1. Use queue data structure.
2. Insert root node into queue.
3. While queue is not empty:
      a. Remove front element.
      b. Print current node.
      c. Insert left child if present.
      d. Insert right child if present.

Note:
Current implementation stores node data in queue
and recursively traverses nodes.

Time Complexity:
O(n)

Space Complexity:
O(n)
*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

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

queue<int> q;
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

// Level Order Traversal:
// Visit nodes level by level
void levelorder_traverse(Node* root) 
{
    // Base condition
    if(root == NULL) {
        return ;
    }
    
    // Insert current node data into queue
    q.push(root->data);
    
    // Print queue elements
    while(q.size() > 0) {
        int curr = q.front();
        q.pop();
        
        cout<<curr<<" ";
    }
    
    // Traverse left subtree
    levelorder_traverse(root->left);
    
    // Traverse right subtree
    levelorder_traverse(root->right);
}

int main()
{
    // Preorder traversal array
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    
    // Build binary tree
    Node* root = buildTree(preorder);
    
    // Print level order traversal
    levelorder_traverse(root);
    
    return 0;
}
