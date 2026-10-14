class Solution {
public:
    string postToInfix(string postExp) {
        stack<string> st;

        for(int i = 0; i < postExp.size(); i++) {
            char ch = postExp[i];

            if(isalnum(ch)) {
                st.push(string(1, ch));
            }
            else {
                string op2 = st.top();
                st.pop();

                string op1 = st.top();
                st.pop();

                string exp = "(" + op1 + ch + op2 + ")";
                st.push(exp);
            }
        }

        return st.top();
    }
};

//TC = O(N) + O(N1 + N2)  ...for + addn of two string takes O(N1 + N2) time where N1 is length of first string & N2 is length of second string. here we are adding op1 & op2 .
//SC = O(N) ...stack