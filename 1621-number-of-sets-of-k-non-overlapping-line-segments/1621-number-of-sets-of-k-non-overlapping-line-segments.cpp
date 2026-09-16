class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(k + 1, 0), pre(k + 1, 0);
        dp[0] = 1;
        pre[0] = 1;

        for (int i = 1; i < n; i++) {
            vector<long long> newDp(k + 1, 0), newPre(k + 1, 0);
            newDp[0] = 1;
            newPre[0] = 1;
            for (int j = 1; j <= k; j++) {
                newDp[j] = (dp[j] + pre[j - 1]) % MOD;
                newPre[j] = (pre[j] + newDp[j]) % MOD;
            }
            dp = newDp;
            pre = newPre;
        }

        return (int)(pre[k] % MOD);
    }
};