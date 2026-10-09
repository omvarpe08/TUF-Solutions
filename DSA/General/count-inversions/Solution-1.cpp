class Solution {
public:
    long long merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long cnt = 0;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
                cnt += (mid - left + 1);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {
        long long cnt = 0;

        if (low >= high) return cnt;

        int mid = low + (high - low) / 2;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);

        return cnt;
    }

    long long int numberOfInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

// Algorithm: Merge Sort

// TC: O(n log n)
// SC: O(n)