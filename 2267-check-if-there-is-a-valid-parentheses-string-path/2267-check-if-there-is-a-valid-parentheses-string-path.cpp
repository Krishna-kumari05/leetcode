class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= m + n; balance++) {

                    // Get balance from current cell
                    int newBalance = balance;

                    if (grid[i][j] == '(')
                        newBalance = balance - 1;
                    else
                        newBalance = balance + 1;

                    if (newBalance < 0)
                        continue;

                    // From top
                    if (i > 0 && dp[i - 1][j][newBalance]) {
                        dp[i][j][balance] = true;
                    }

                    // From left
                    if (j > 0 && dp[i][j - 1][newBalance]) {
                        dp[i][j][balance] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};