class Solution {
public:
    TreeNode* lca(TreeNode* root, int p, int q) {

        while(root != NULL) {
            if(p < root->data && q < root->data) {
                root = root->left;
            }
            else if(p > root->data && q > root->data) {
                root = root->right;
            }
            else {
                return root;
            }
        }

        return NULL;
    }
};

//TC: O(H) – H is the height of the BST.
//SC: O(1) – No extra space.