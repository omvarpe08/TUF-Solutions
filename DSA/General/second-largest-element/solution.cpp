class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int largest = nums[0];
        int slargest = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > largest) {
                slargest = largest;
                largest = nums[i];
            }
            else if (nums[i] < largest && nums[i] > slargest) {
                slargest = nums[i];
            }
        }

        if (slargest == INT_MIN)
            return -1;

        return slargest;
    }
};

// TC = O(n)
// SC = O(1)