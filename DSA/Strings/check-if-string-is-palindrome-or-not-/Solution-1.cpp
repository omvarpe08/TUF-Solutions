class Solution {
public:
    bool palindromeCheck(string& s) {
        return f(0, s);
    }

    bool f(int i, string& s) {
        if (i >= s.size() / 2)
            return true;

        if (s[i] != s[s.size() - i - 1])
            return false;

        return f(i + 1, s);
    }
};

// TC = O(n)
// SC = O(n)  // Recursive call stack
//there is one more this kind of better problm in leetcode
