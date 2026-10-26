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
        TreeNode* temp = root;

        while (temp->left != NULL) {
            temp = temp->left;
        }
        int mini = temp->val;

        temp = root;

        while (temp->right != NULL) {
            temp = temp->right;
        }
        int maxi = temp->val;

        return {mini, maxi};
    }
};

//since u r travelling twice height of tree thus u can say complexity will atmax twicw height of tree which is mostly 2*Log2 N.
//TC = O(2h) = O(2*Log2 N) = O(Log2 N)
//SC = O(1);