/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    // Function to calculate height of tree
    int height(TreeNode* root) 
    {
        // Step 1:
        // If node is NULL, height is 0
        if(root == NULL) {
            return 0;
        }

        // Step 2:
        // Find height of left subtree
        int leftheight = height(root->left);

        // Step 3:
        // Find height of right subtree
        int rightheight = height(root->right);

        // Step 4:
        // Return maximum height + current node
        return max(leftheight, rightheight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        // Step 1:
        // If tree is empty, diameter is 0
        if(root == NULL) {
            return 0;
        }

        // Step 2:
        // Find diameter of left subtree
        int leftdiameter = diameterOfBinaryTree(root->left);

        // Step 3:
        // Find diameter of right subtree
        int rightdiameter = diameterOfBinaryTree(root->right); 

        // Step 4:
        // Find diameter passing through current node
        int currdiameter = height(root->left) + height(root->right);  

        // Step 5:
        // Return maximum among:
        // current diameter,
        // left subtree diameter,
        // right subtree diameter
        return max(currdiameter,
                   max(rightdiameter, leftdiameter));
    }
};
