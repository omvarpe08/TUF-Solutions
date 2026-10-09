class Solution {
public:
    int pascalTriangleI(int r, int c) {
        long long ans = 1;

        for (int col = 1; col < c; col++) {
            ans = ans * (r - col);
            ans = ans / col;
        }

        return ans;
    }
};

// TC = O(c)
// SC = O(1)