class Solution {
public:
    string prefixToInfix(string s) {
       stack<string> st;

        for(int i = s.size()-1; i >= 0; i--) {
            char ch = s[i];

            if(isalnum(ch)) {
                st.push(string(1, ch));
            }
            else {
                string op1 = st.top();
                st.pop();

                string op2 = st.top();
                st.pop();

                string exp ="(" + op1 + ch + op2 + ")" ;
                st.push(exp);
            }
        }

        return st.top();
    }
    
};