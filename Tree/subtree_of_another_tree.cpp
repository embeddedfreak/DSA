class Solution {
public:

    // Step 1:
    // Create a helper function to check whether two trees
    // are completely identical or not.
    bool isIdentical(TreeNode* p, TreeNode* q)
    {
        // Step 2:
        // If either node becomes NULL,
        // return true only when both are NULL.
        if(p == NULL || q == NULL) {
            return p == q;
        }

        // Step 3:
        // Check:
        // 1. Current node values are equal
        // 2. Left subtrees are identical
        // 3. Right subtrees are identical
        return (p->val == q->val &&
                isIdentical(p->left, q->left) &&
                isIdentical(p->right, q->right));

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Step 4:
        // If either tree becomes NULL,
        // subtree exists only when both are NULL.
        if(root == NULL || subRoot == NULL) {
            return root == subRoot; 
        }

        // Step 5:
        // If current node values match,
        // check whether both trees are identical.
        if(root->val == subRoot->val && isIdentical(root, subRoot)) {
            return true;
        }

        // Step 6:
        // Recursively search for subtree
        // in left subtree or right subtree.
        return (isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot));
        
    }
};
