class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Count frequency of every number
        vector<int> freq(51, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // Case 1: k == n
        // There is only one subarray: the whole array.
        // Therefore, every number appearing in nums
        // appears in exactly one subarray.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 2: k == 1
        // Every element itself is a subarray.
        // So a number is almost missing iff it occurs exactly once.
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 3: 1 < k < n
        // Only the first and last elements can belong
        // to exactly one subarray of length k.

        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};