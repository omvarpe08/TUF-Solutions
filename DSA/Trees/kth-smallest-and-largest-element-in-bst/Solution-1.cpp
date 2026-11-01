class Solution {
public:
    int small, large;
    int count = 0;

    void inorder(TreeNode* root, int k, int n) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, k, n);

        count++;

        if (count == k) {
            small = root->data;
        }

        if (count == n - k + 1) {
            large = root->data;
        }

        inorder(root->right, k, n);
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    vector<int> kLargesSmall(TreeNode* root, int k) {
        int n = countNodes(root);

        small = -1;
        large = -1;

        inorder(root, k, n);

        return {small, large};
    }
};
//Soln - 1
//we assign -1 to small & large bcoz what if we dont get any small & large 

//Time Complexity: O(2N) = O(N) – counting nodes + inorder traversal.
//Space Complexity: O(H) – recursive stack.