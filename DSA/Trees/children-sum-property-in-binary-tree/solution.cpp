/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:

    int mxdepth(TreeNode* root , bool &flag) {
        if(root == NULL) {
            return 0;
        }
        int left = mxdepth(root->left , flag);
        int right = mxdepth(root->right , flag);

        if(left + right != root->val && (root->left != NULL || root->right != NULL)) {
            flag = false;
        }

        return root->val;
    }
    bool checkChildrenSum(TreeNode* root) {
        bool flag = true;
        mxdepth(root , flag);
        return flag;
    }
};
