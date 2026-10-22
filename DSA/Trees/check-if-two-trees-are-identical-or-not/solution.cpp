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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) {
            return p==q;
        }

        return (p->data == q->data)
            && isSameTree(p->left , q->left)
            && isSameTree(p->right , q->right);

    }
};

//TC = O(N)  ...treversing each node

//SC = O(H)  ..auxiliary space for the recursion stack, where H is the tree's height;                        
//worst case : Degenerate (Skewed) Binary Tree O(N), 
//Best Case : balanced tree O(log N).

