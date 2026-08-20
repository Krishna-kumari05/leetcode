class Solution {
public:
    int fibo(int index){
        vector<int>dp(index+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=index;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[index];
    }
    int climbStairs(int n) {
       return  fibo(n);
    }
};