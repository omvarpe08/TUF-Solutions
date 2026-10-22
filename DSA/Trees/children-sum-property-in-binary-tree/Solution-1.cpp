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

//same soln with little more standerd way in tab 2

//TC = O(N)   ...travesing all nodes

//SC: O(H) auxiliary space for recursion, where H is the tree height. 
//worst case : Degenerate (Skewed) Binary Tree O(N), Best Case : balanced tree O(log N).
