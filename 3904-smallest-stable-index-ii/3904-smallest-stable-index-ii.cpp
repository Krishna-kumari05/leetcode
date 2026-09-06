class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixmax(n, 0);
        vector<int> suffixmin(n, 0);

        prefixmax[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i-1], nums[i]);
        }

        int mn = nums[n-1];

        suffixmin[n-1] = prefixmax[n-1] - mn;

        for(int i = n-2; i >= 0; i--) {

            mn = min(mn, nums[i]);

            suffixmin[i] = prefixmax[i] - mn;
        }

        for(int i = 0; i < n; i++) {
            if(suffixmin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};