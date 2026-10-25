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
    TreeNode* searchBST(TreeNode* root, int data) {

        while(root != NULL && root->data != data) {
            root = data < root->data ? root->left : root->right;
        }
        return root;
    }
};

//here u can see u are traveling somewhere around height of tree or less than that & we know for BST height is mostly log2 N thus,

//TC = O(Log2 N)
//SC = O(1)