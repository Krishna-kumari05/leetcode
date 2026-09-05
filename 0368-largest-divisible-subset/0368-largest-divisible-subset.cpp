class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> hash(n, -1);
        vector<int> dp(n, 1);

        int ans = 1;
        int lastindex = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] == 0 &&
                    dp[i] < dp[j] + 1) {

                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (dp[i] > ans) {
                ans = dp[i];
                lastindex = i;
            }
        }

        vector<int> temp;

        int i = lastindex;

        while (i != -1) {
            temp.push_back(nums[i]);
            i = hash[i];
        }

        return temp;
    }
};