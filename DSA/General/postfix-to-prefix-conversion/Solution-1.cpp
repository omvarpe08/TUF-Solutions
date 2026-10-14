class Solution {
public:
    string postToPre(string postfix) {
        stack<string> st;

        for(int i = 0; i < postfix.size(); i++) {
            char ch = postfix[i];

            if(isalnum(ch)) {
                st.push(string(1, ch));
            }
            else {
                string op2 = st.top();
                st.pop();

                string op1 = st.top();
                st.pop();

                string exp = ch + op1 + op2 ;
                st.push(exp);
            }
        }

        return st.top();
    }
};

//TC = O(N) 
//SC = O(N) ...stack