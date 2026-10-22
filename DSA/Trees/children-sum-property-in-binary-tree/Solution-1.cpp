/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if(root == NULL) {
            return true;
        }

        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        
        int sum = 0;

        if(root->left != NULL) {
            sum += root->left->val;
        }
        
        if(root->right != NULL) {
            sum += root->right->val;
        }

        if(sum != root->val) {
            return false;
        }

        return checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};
