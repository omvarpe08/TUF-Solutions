
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return NULL;
        }

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }

        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }

        else {
            // Case 1: No left child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: No right child
            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Both children exist
            TreeNode* temp = root->right;

            // Find inorder successor
            while (temp->left != NULL) {
                temp = temp->left;
            }

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }
};


//Time Complexity: O(H) ...where H is the height of BST.
//Space Complexity: O(H) ...due to recursion stack.