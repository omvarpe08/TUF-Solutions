class Solution {
public:
    string prefixToInfix(string s) {
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

                st.push("(" + op1 + ch + op2 + ")");
            }
        }

        return st.top();
    }
};

//TC = O(N) + O(N1 + N2)  ...for + addn of two string takes O(N1 + N2) time where N1 is length of first string & N2 is length of second string. here we are adding op1 & op2 .
//SC = O(N) ...stack