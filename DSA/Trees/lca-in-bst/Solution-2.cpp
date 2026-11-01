/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : data(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, int p, int q) {
        int curr = root->data;

        if(curr > p && curr > q) {
            return lca(root->left , p , q);
        }
        if(curr < p && curr < q) {
            return lca(root->right , p , q);
        }

        return root;
    }
};

//TC = O(H)  
//SC = O(H)  ...recursion stack