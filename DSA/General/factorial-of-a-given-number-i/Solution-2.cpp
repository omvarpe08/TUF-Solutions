class Solution {
public:
    int factorial(int n) {
        if (n == 0)
            return 1;

        return n * factorial(n - 1);
    }
};

// TC = O(n)
// SC = O(n)  // Recursive call stack