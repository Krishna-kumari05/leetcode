class Solution {
public:
    int solve(int i, int M, vector<int>& piles, vector<vector<int>>& dp,
              vector<int>& suffix) {
        
        int n = piles.size();

        // All remaining stones can be taken
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // If we take all remaining piles
        if (i + 2 * M >= n)
            return dp[i][M] = suffix[i];

        // Try taking X piles, where 1 <= X <= 2*M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            // Current player takes first X piles.
            // Opponent then gets solve(i+X, max(M,X)).
            int opponent = solve(i + X, max(M, X), piles, dp, suffix);

            // Total remaining stones - opponent's stones
            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = sum of piles from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones current player can get
        // starting from index i with current M
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles, dp, suffix);
    }
};