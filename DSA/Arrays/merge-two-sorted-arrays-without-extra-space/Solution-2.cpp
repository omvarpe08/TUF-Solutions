class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr(m + n);
        int left = 0, right = 0, index = 0;

        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                arr[index++] = nums1[left++];
            } else {
                arr[index++] = nums2[right++];
            }
        }

        while (left < m) {
            arr[index++] = nums1[left++];
        }

        while (right < n) {
            arr[index++] = nums2[right++];
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = arr[i];
        }
    }
};

// TC: O(m + n)
// SC: O(m + n)