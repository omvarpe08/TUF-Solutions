class Solution {
public:
    int factorial(int n) {
        int fact = 1;
        int i = 1;

        while (i <= n) {
            fact = fact * i;
            i++;
        }

        return fact;
    }
};

// TC = O(n)
// SC = O(1)