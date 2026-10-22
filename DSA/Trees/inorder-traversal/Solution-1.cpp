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

//SC = O(H)  ..auxiliary space for the recursion stack, where H is the tree height;                        worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).

//u might think that recursion stack should O(N) but no bcoz the key point is that stack space is the number of calls waiting at the same time & it depends on the tree's height H, not the total number of nodes N.

//what about vector<int> ans - generally we wont consider it bcoz it is something which we are using for retruning ans.
//Output space: O(N) ...ans vector.
