class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++){
            t+=nums[i];
        }
        if((t-target<0)|| (t-target)%2!=0) return 0;
        
        int sum=(t-target)/2;

        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0] == 0) {
            dp[0][0] = 2;
        }
        else {
             dp[0][0] = 1;

            if(nums[0] <= sum) {
               dp[0][nums[0]] = 1;
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int j=0;j<=sum;j++){
                int nottake=dp[ind-1][j];
                int take=0;
                if(j>=nums[ind]){
                    take=dp[ind-1][j-nums[ind]];
                }
                dp[ind][j]=take+nottake;
            }
        }
        return dp[n-1][sum];
    }
};