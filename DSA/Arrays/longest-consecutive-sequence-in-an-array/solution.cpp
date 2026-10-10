class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int lastSmaller = INT_MIN;
        int cnt = 0, longest = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 == lastSmaller) {
                cnt++;
                lastSmaller = nums[i];
            }
            else if (nums[i] != lastSmaller) {
                cnt = 1;
                lastSmaller = nums[i];
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};

// Better
// TC: O(n log n)
// SC: O(1) auxiliary space