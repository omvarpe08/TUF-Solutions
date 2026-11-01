class Solution {
public:

    bool isBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }

    bool check(TreeNode* root, long long mini, long long maxi) {
        if (root == NULL) {
            return true;
        }

        if (root->data <= mini || root->data >= maxi) {
            return false;
        }

        return check(root->left, mini, root->data) &&
               check(root->right, root->data, maxi);
    }

};

//TC: O(N) – Visit every node once.
//SC: O(H) – Recursive stack, where H is tree height.