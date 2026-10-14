class Solution {
public:
    string prefixToPostfix(const string& s) {
        stack<string> st;

        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (isalnum(ch)) {
                st.push(string(1, ch));
            }
            else {
                string op1 = st.top();
                st.pop();

                string op2 = st.top();
                st.pop();

                st.push(op1 + op2 + ch);
            }
        }

        return st.top();
    }
};

//TC = O(2N) = O(N)  ...N for for loop & N for addn of two string takes O(N1 + N2) time where N1 is length of first string & N2 is length of second string which might be O(N) in worst case.

//SC = O(N)  ...stack