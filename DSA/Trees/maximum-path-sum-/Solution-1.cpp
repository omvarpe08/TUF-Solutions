/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : data(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum(TreeNode* root, int &sum) {

        if(root == NULL){
            return 0;
        }

        int leftSum = max(0 , maxSum(root->left, sum));
        int rightSum = max(0 , maxSum(root->right, sum));
        sum = max(sum , leftSum + rightSum + root->data);

        return root->data + max(leftSum , rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int s = INT_MIN;
        maxSum(root , s);
        return s;
    }
};

//TC = O(N)   ...travesing all nodes

//SC: O(H) auxiliary space for recursion, where H is the tree height. 
//worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).