/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 * };
 */

class Solution {
public:
    vector<int> findMinMax(TreeNode* root) {

        int maxm;
        int minm;
        TreeNode* curr = root;

        while(curr != NULL) {
            maxm = curr->val;
            curr = curr->right;
        }

        curr = root;

         while(curr != NULL) {
            minm = curr->val;
            curr = curr->left;
        }
        return {minm , maxm};
    }
};