
class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPostfix(string s) {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Operand
            if (isalnum(ch)) {           
                ans += ch;
            }

            /*
            if( s[i] >= 'a' && s[i] <= 'z' || 
                s[i] >= 'A' && s[i] <= 'Z' || 
                s[i] >= '0' && s[i] <= '9') {
                ans.push_back(s[i]);
            }

            also can be done this way both are same.
            */

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
                        ch != '^'))) {
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

        return ans;
    }
};


//string ans = "";  ...here we have declare like this bcoz we wants to do operation like this -                     ans += ch; for adding element in ans.

//string ans;       ...if we have done this way then to add element in ans we need to do 
//                     ans.push_back(ch) for such operation

//TC = O(N)+O(N) = O(2N) = O(N)      ... for loop [O(N)] + while loop (in every while loop we are just poping element & we know we can pop each element just once from stack & we have maxm of N element. thus we can pop maxm N times. thus while loop can run maxm N times. thus O(N) for this).

//SC = O(N)+O(N) = O(2N) = O(N)      ...stack st + string ans
