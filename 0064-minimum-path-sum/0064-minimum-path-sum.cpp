class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int down=grid[i][j]+dp[i-1][j];
                int right=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(down,right);
            }
        }
        return dp[m-1][n-1];
    }
};