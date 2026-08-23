class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<i+1;j++){
                if (j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else if(j==i){
                    dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                }
                else{
                    int down=triangle[i][j]+dp[i-1][j];
                    int diag=triangle[i][j]+dp[i-1][j-1];
                    dp[i][j]=min(down,diag);
                }
            }
        }
        int ans=INT_MAX;
         for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;

    }
};