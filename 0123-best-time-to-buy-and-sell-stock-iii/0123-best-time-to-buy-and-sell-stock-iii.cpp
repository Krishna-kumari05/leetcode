class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        dp[n][0][0]=0;
        dp[n][1][1]=0;
        dp[n][1][2]=0;
        dp[n][1][0]=0;
        
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int cap=1;cap<=2;cap++){
                    if(j){
                        profit=max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else{
                        profit=max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                    dp[i][j][cap] = profit;
                }
            }
           
        }
        return profit;
    }
};