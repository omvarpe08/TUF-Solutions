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
		vector<int> inorder(TreeNode* root){
	        vector<int> inorder;

            TreeNode* Node = root;

            if(root == NULL) {
                return inorder;
            } 

            stack<TreeNode*> st;

            while(true) {
                if(Node != NULL) {
                    st.push(Node);
                    Node = Node->left;
                }

                else {
                    if(st.empty()) {
                        break;
                    }
                    Node = st.top();
                    st.pop();
                    inorder.push_back(Node->data);
                    Node = Node->right;
                }
            }

            return inorder;   

        }
};

//Iterative
//TC = O(N)  ...N : num of node
//              we are travesing at each node thus O(N);

//SC = O(H)   ...here stack can store maxm of H node same time, where H is the tree height.
//              ...worst case : Degenerate (Skewed) Binary Tree O(N)
//              ...Auxiliary SC

//Output space: O(N) for the preorder vector.