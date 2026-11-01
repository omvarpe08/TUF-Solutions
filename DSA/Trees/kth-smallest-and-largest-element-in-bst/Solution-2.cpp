class Solution {
public:
    int small, large;

    void inorder(TreeNode* root, int &k) {
        if (root == NULL || k == 0) {
            return;
        }

        inorder(root->left, k);

        k--;

        if (k == 0) {
            small = root->data;
            return;
        }

        inorder(root->right, k);
    }

    void reverseInorder(TreeNode* root, int &k) {
        if (root == NULL || k == 0) {
            return;
        }

        reverseInorder(root->right, k);

        k--;

        if (k == 0) {
            large = root->data;
            return;
        }

        reverseInorder(root->left, k);
    }

    vector<int> kLargesSmall(TreeNode* root, int k) {
        small = -1;
        large = -1;

        int k1 = k;
        int k2 = k;

        inorder(root, k1);
        reverseInorder(root, k2);

        return {small, large};
    }
};

//Soln - 2
//To preserve the original k value and we use k1 & k2 , since k gets modified during recursion.

//Time Complexity: O(2N) = O(N) worst case.
//Space Complexity: O(H), recursion stack.