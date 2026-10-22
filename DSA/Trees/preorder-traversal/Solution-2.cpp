/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<int> preorder(TreeNode* root){
	        vector<int> preorder;

            if(root == NULL) {
                return preorder;
            }

            stack<TreeNode*> st;

            st.push(root);

            while(!st.empty()) {
                root = st.top();
                st.pop();

                preorder.push_back(root->data);

                if(root->right != NULL) {
                    st.push(root->right);
                }

                if(root->left != NULL) {
                    st.push(root->left);
                } 
            }

            return preorder;
		}
};

//Iterative
//TC = O(N)  ...N : num of node
//              we are travesing at each node thus O(N);

//SC = O(H)   ...here stack can store maxm of H node same time, where H is the tree height.
//              ...worst case : Degenerate (Skewed) Binary Tree O(N)
//              ...Auxiliary SC

//Output space: O(N) for the preorder vector.