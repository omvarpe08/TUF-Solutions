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
	        vector<int> ans;

            if(root == NULL) {
                return ans;
            }

            stack<TreeNode*> st;

            st.push(root);

            while(!st.empty()) {
                root = st.top();
                st.pop();

                ans.push_back(root->data);

                if(root->right != NULL) {
                    st.push(root->right);
                }

                if(root->left != NULL) {
                    st.push(root->left);
                } 
            }

            return ans;
		}
};

//Iterative
//TC = O(N)  ...N : num of node
//              we are travesing at each node thus O(N);

//SC = O(N)   ...in worst case stack stores n nodes.