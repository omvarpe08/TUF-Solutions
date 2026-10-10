class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0]++;

        int xr = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            xr ^= nums[i];

            int x = xr ^ k;
            cnt += mpp[x];

            mpp[xr]++;
        }

        return cnt;
    }
};

// TC: O(n) average
// SC: O(n)