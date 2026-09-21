class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        
        vector<long long> prev(k, 0);
        vector<long long> curr(k, 0);

        for (int x : nums) {
            fill(curr.begin(), curr.end(), 0);
            curr[x % k]++;
            for (int r = 0; r < k; r++) {
                if (prev[r] > 0) {
                    int newRem = (r * 1LL * (x % k)) % k;
                    curr[newRem] += prev[r];
                }
            }


            for (int r = 0; r < k; r++) {
                ans[r] += curr[r];
            }

            prev = curr;
        }

        return ans;
    }
};