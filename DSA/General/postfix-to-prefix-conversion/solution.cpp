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

//TC = O(2N) = O(N)  ...N for for loop & N for addn of two string takes O(N1 + N2) time where N1 is length of first string & N2 is length of second string which might be O(N) in worst case.

//SC = O(N) ...stack