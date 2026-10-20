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

            if(root == NULL) {
                return postorder;
            }

	        stack<TreeNode*> st1,st2;

            st1.push(root);

            while(!st1.empty()) {
                root = st1.top();
                st1.pop();
                st2.push(root);

                if(root->left != NULL) {
                    st1.push(root->left);
                }

                if(root->right != NULL) {
                    st1.push(root->right);
                }
            }

            while(!st2.empty()) {
                postorder.push_back(st2.top()->data);
                st2.pop();
            }
            return postorder;
		}
};

//Iterative - 1 (2 stack)
//TC = O(N)  ...N : num of Node
//              we are travesing at each node thus O(N);

//SC = O(2N)   ...2 stacks