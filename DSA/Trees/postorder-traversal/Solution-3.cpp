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
		vector<int> postorder(TreeNode* root){
	        vector<int> postorder;
            stack<TreeNode*> st;

            TreeNode* curr = root;

            while(!st.empty() || curr != NULL) {
                if(curr != NULL) {
                    st.push(curr);
                    curr = curr->left;
                }

                else {
                    TreeNode* temp = st.top()->right;

                    if(temp == NULL) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->data);

                        while(!st.empty() && temp == st.top()->right) {
                            temp = st.top();
                            st.pop();
                            postorder.push_back(temp->data);
                        }
                    }
                    else {
                        curr = temp;
                    }
                }
                
            }
            return postorder;
		}
};
//remember code is little harder so give little more effort on it
//Iterative - 2 (1 stack)
//TC = O(2N)  ...N : num of Node
//              we are travesing at each node twice thus O(2N);

//SC = O(N)  ...here we are also using vector<int> postorder but we can ignore it bcoz we are using it for storing or returning answer.