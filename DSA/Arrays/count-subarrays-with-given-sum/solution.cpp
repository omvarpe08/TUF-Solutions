class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mpp;
        mpp[0] = 1;

        long long preSum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];

            long long remove = preSum - k;
            cnt += mpp[remove];

            mpp[preSum]++;
        }

        return cnt;
    }
};

// TC: O(n) average
// SC: O(n)