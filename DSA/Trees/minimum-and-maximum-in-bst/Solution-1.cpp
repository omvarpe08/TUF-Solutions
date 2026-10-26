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

//Another way of writing this code is in tab 2.

//since u r travelling twice height of tree thus u can say complexity will atmax twicw height of tree which is mostly 2*Log2 N.
//TC = O(2h) = O(2*Log2 N) = O(Log2 N)
//SC = O(1);