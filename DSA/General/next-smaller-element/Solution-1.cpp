
class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};

//TC = O(N + N) = O(2N) = O(N)     ...for + while 
//...here by while loop we are just poping element & we know we can pop each element just once from stack & we have total of N element. thus we can pop maxm N times. thus while loop can run maxm N times. thus O(N) for this.

//SC = O(N)  ...ans (in it we are storing next greater element of each element thus O(N) for this)