class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        map<int ,int>mp;
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
               sum+=nums[i];
            }
            else{
                break;
            }
        }
        while(true){
            if(find(nums.begin(),nums.end(),sum)==nums.end()){
                return sum;
            }
            else{
                sum++;
            }
        }
    }
};