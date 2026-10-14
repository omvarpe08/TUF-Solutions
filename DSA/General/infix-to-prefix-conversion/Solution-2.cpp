
class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
    }

    string infixToPrefix(const string& s) {
        stack<char> st;
        string ans;

        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (isalnum(ch)) {
                ans += ch;
            }
            else if (ch == ')') {
                st.push(ch);
            }
            else if (ch == '(') {
                while (!st.empty() && st.top() != ')') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else {
                while (!st.empty() && st.top() != ')' &&
                       (priority(st.top()) > priority(ch) ||
                       (priority(st.top()) == priority(ch) &&
                        ch == '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//TC = O(N) + O(N) + O(N/2) = O(N) ...for + all while + reverse
//SC = O(N) + O(N) ..stack st + string ans