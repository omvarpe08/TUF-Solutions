class Solution {
public:
    vector<int> moveZeroes(int n, vector<int> a) {
        int j = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                j = i;
                break;
            }
        }

        // No non-zero numbers
        if (j == -1) return a;

        for (int i = j + 1; i < n; i++) {
            if (a[i] != 0) {
                swap(a[i], a[j]);
                j++;
            }
        }

        return a;
    }
};

//Optimal
// TC = O(n)
// SC = O(1)