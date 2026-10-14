class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPrefix(const string& s) {
        string srev = "";
        for(int i=s.size()-1; i>=0; i--) {
            srev += s[i];
        }

        for(int i=0; i<srev.size(); i++) {
            if(srev[i] == '(') {
                srev[i] = ')';
            }
            else if(srev[i] == ')') {
                srev[i] = '(';
            }
        }

        stack<char> st;
        string ans = "";

        for (int i = 0; i < srev.size(); i++) {
            char ch = srev[i];

            // Operand
            if (isalnum(ch)) {           
                ans += ch;
            }

            // Opening bracket
            else if (ch == '(') {
                st.push(ch);
            }

            // Closing bracket
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Remove '('
            }

            // Operator
            else {
                while (!st.empty() && st.top() != '(' &&
                       (priority(st.top()) > priority(ch) ||
                       (priority(st.top()) == priority(ch) &&
                        ch == '^'))) {
                    ans += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        string ansrev ="";

        for(int i=ans.size()-1; i>=0; i--) {
            ansrev+=ans[i];
        }
        return ansrev;
    }
};