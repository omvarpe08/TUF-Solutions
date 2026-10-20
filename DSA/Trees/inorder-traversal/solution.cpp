/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }

    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

//TC = O(N)  ...N : num of node
//              we are travesing at each node thus O(N);

//SC = O(N)   ...recursion stack bcoz funcn's are ging to wait in stack to be completed & O(N) bcoz we calculate TC & SC for worst case & in worst case N node is going to wait in stack to be completed. 
//i.e for Degenerate (Skewed) Binary Tree