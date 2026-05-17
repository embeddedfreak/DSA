#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node structure for Binary Tree
class Node {
public: 
    int data;
    Node* left;
    Node* right;
    
    // Constructor to initialize node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

/*
    Function to build Binary Tree using preorder traversal

    Algorithm:
    ----------
    1. Increment index.
    2. If current value is -1:
        -> return NULL.
    3. Create new node using current value.
    4. Recursively build left subtree.
    5. Recursively build right subtree.
    6. Return root node.
*/
Node* buildTree(vector<int> preorder)
{
    idx++;
    
    // Base condition for NULL node
    if(preorder[idx] == -1) {
        return NULL;
    }
    
    // Create node
    Node* root = new Node(preorder[idx]);
    
    // Build left subtree
    root->left = buildTree(preorder);
    
    // Build right subtree
    root->right = buildTree(preorder);
    
    return root;
}

/*
    Level Order Traversal (Breadth First Search)

    Algorithm:
    ----------
    1. If tree is empty, return.
    2. Create queue and push root node.
    3. Repeat until queue becomes empty:
        a. Get front node.
        b. Remove node from queue.
        c. Print node data.
        d. Push left child if exists.
        e. Push right child if exists.
*/
void levelorder_traverse(Node* root) 
{
    // Check for empty tree
    if(root == NULL) {
        return ;
    }

    // Queue used for BFS traversal
    queue<Node*> q;

    // Push root node into queue
    q.push(root);
    
    // Traverse until queue becomes empty
    while(q.size() > 0) {

        // Get front node
        Node* curr = q.front();

        // Remove front node
        q.pop();

        // Print current node
        cout<<curr->data<<" ";
        
        // Push left child into queue
        if(curr->left!=NULL)
            q.push(curr->left);

        // Push right child into queue
        if(curr->right!=NULL)
            q.push(curr->right);

    }

}

int main()
{
    // Preorder representation of binary tree
    vector<int> preorder = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };
    
    // Build tree
    Node* root = buildTree(preorder);
    
    // Perform level order traversal
    levelorder_traverse(root);
    
    return 0;
}
