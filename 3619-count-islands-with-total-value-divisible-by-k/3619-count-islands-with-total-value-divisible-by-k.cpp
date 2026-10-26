class Solution {
public:
    int m, n;

    long long dfs(vector<vector<int>>& grid, int i, int j, int k) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;

        long long sum = grid[i][j];
        grid[i][j] = 0;

        sum += dfs(grid, i + 1, j, k);
        sum += dfs(grid, i - 1, j, k);
        sum += dfs(grid, i, j + 1, k);
        sum += dfs(grid, i, j - 1, k);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    long long sum = dfs(grid, i, j, k);

                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};