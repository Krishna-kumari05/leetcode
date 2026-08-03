class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&piles,int i){
        int n=piles.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=INT_MIN){
            return dp[i];
        }
        
        int take1=piles[i]-solve(piles,i+1);
        int take2=INT_MIN;
        if(i+1<n){
           take2=piles[i]+piles[i+1]-solve(piles,i+2);
        }
        int take3=INT_MIN;
        if(i+2<n){
            take3=piles[i]+piles[i+1]+piles[i+2]-solve(piles,i+3);
        }
        int ans=max(take1,take2);
        int final=max(ans,take3);
      
        return dp[i]=final;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.assign(n,INT_MIN);
        int ans=solve(stoneValue,0);
        if (ans>0){
            return "Alice";
        }
        else if(ans<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};