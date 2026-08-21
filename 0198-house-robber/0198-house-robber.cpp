class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0;
        int curi=0;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i]+prev2;
            int nottake=prev;
             curi=max(take,nottake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};