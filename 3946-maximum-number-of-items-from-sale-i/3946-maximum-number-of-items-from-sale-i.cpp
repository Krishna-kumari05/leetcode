
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;
        vector<int> freeCnt(n, 0);

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    freeCnt[i]++;
            }
        }

        vector<int> dp(budget + 1, -1000000);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int gain = freeCnt[i] + 1;

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + gain);
            }
        }

        int ans = 0;

        for (int j = 0; j <= budget; j++) {
            if (dp[j] >= 0)
                ans = max(ans, dp[j] + (budget - j) / minPrice);
        }

        return ans;
    }
};
