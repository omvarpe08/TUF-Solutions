class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i = 2*n-1; i>=0; i--) {
            while(!st.empty() && arr[i%n] >= st.top()) {
                st.pop();
            }

            if(st.empty()) {
                ans[i%n] = -1;
            }
            else {
                ans[i%n] = st.top();
            }

            st.push(arr[i%n]);
        }
        return ans;
    }
};

//1

//TC = O(2N + 2N)   ...for + while 
//...here by while loop we are just poping element & we know we can pop each element just once from stack & we are pushing total of 2N element in stack. thus we can pop maxm 2N times. thus while loop can run maxm 2N times. thus O(2N) for this.