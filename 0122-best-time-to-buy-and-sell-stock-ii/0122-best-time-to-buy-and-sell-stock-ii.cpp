class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();   
       int buy=0;
        int sell=0;
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    profit=max(-prices[i]+sell,buy);
                    buy=profit;
                }
                else{
                    profit=max(prices[i]+buy,sell);
                    sell=profit;
                }
            }
           
        }
        return profit;
    }
};