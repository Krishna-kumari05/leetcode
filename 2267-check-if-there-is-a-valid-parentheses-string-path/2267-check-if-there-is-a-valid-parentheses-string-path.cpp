
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        if ((m + n) % 2 == 0) {
            return false;
        }

        vector<vector<bool>> dp(m, vector<bool>(n, false));

        vector<vector<unordered_set<int>>> balance(
            m, vector<unordered_set<int>>(n)
        );

        if (grid[0][0] == '(') {
            balance[0][0].insert(1);
        } else {
            return false;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int b : balance[i][j]) {
            
                    if (i + 1 < m) {
                        int next = b + (grid[i + 1][j] == '(' ? 1 : -1);
                        if (next >= 0 && next <= m + n) {
                            balance[i + 1][j].insert(next);
                        }
                    }

                   
                    if (j + 1 < n) {
                        int next = b + (grid[i][j + 1] == '(' ? 1 : -1);
                        if (next >= 0 && next <= m + n) {
                            balance[i][j + 1].insert(next);
                        }
                    }
                }
            }
        }

        return balance[m - 1][n - 1].count(0) > 0;
    }
};
