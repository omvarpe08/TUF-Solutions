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