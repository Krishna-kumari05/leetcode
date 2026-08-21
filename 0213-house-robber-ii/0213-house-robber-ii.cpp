class Solution {
public:

    int solve(vector<int>&nums,int start ,int end){
        int prev2=0;
        int curi=0;
        int prev=nums[start];
        for(int i=start+1;i<end;i++){
            int take=nums[i]+prev2;
            int nottake=prev;
             curi=max(take,nottake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
            int n=nums.size();
            if(n == 1)
                return nums[0];
            int first= solve(nums,0,n-1);
            int second= solve(nums,1,n);
            return max(first,second);
    }
};