class Solution {
public:
    int countDigit(int n) {
        int cnt = 0;

        if (n == 0)
            return 1;

        while (n > 0) {
            cnt++;
            n = n / 10;
        }

        return cnt;
    }
};

// Algorithm - Repeated Division by 10
// TC = O(log10(n))
// SC = O(1)

// Special Case - If n = 0, answer is 1.
// Each division by 10 removes one digit.