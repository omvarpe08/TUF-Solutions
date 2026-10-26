/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
            int floor = -1;
            int ceil = -1;
            TreeNode* curr = root;

			while(curr != NULL) {
                if(curr->data == key) {
                    ceil = curr->data;
                    floor = curr->data;
                    return {floor , ceil};
                }
                else if(curr->data < key){
                    floor = curr->data;
                    curr = curr->right;
                }
                else {
                    ceil = curr->data;
                    curr = curr->left;
                }
            }

            return {floor,ceil};
		}
};

//since u r travelling height of tree thus u can say complexity will atmax height of tree which is mostly Log2 N.
//TC = O(h) = O(Log2 N)
//SC = O(1);