class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        // Using only coin[0]
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) {
                dp[0][t] = 1;
            }
        }

        // Every amount 0 has exactly one way: choose nothing
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= amount; t++) {

                long long nottake = dp[i - 1][t];

                long long take = 0;
                if (t >= coins[i]) {
                    take = dp[i][t - coins[i]];
                }

               dp[i][t] = min(1LL * INT_MAX, take + nottake);
            }
        }

        return (int)dp[n - 1][amount];
    }
};