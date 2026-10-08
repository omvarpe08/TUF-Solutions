class Solution {
public:
    bool isPalindrome(int n) {
        int revNum = 0;
        int dup = n;

        while (n > 0) {
            int ld = n % 10;
            revNum = (revNum * 10) + ld;
            n = n / 10;
        }

        if (dup == revNum)
            return true;
        else
            return false;
    }
};

// TC = O(log10(n))
// SC = O(1)