class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        vector<int> idx(n);

        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> ans(n);

        
        for (int i = 0; i < n; ) {

            int j = i + 1;

           
            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

           
            vector<int> positions(
                idx.begin() + i,
                idx.begin() + j
            );

            sort(positions.begin(), positions.end());

            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

          
            i = j;
        }

        return ans;
    }
};