class Solution {
public:

    /*
        Function to check whether two binary trees are identical

        Algorithm:
        ----------
        1. If either node becomes NULL:
            -> return true only if both are NULL.
        2. Recursively compare left subtrees.
        3. Recursively compare right subtrees.
        4. Check whether current node values are equal.
        5. Return true only if:
            - left subtrees are identical
            - right subtrees are identical
            - current node values are equal

        Time Complexity  : O(n)
        Space Complexity : O(h)
            where h = height of tree (recursive stack)
    */

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base condition:
        // Returns true if both are NULL
        // Returns false if only one is NULL
        if(p == NULL || q == NULL) {
            return p == q;
        }

        // Compare left subtree
        bool leftIdent = isSameTree(p->left, q->left);

        // Compare right subtree
        bool rightIdent = isSameTree(p->right, q->right);

        // Return true only if:
        // 1. Left subtree identical
        // 2. Right subtree identical
        // 3. Current node values same
        return leftIdent && rightIdent && p->val == q->val;
        
    }
};
