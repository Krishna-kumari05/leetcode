class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int ,int>m;
        int l=0;
        int r=0;
        if(k==0){
            return 0;
        }
        int len=0;
        while(l<=r && r<nums.size()){
            if(m.find(nums[r])!=m.end()){
                if(m[nums[r]]<=k-1){
                    m[nums[r]]++;
                    r++;
                }
                else{
                    m[nums[l]]--;
                    l++;
                }
            }
            else{
                m[nums[r]]=1;
                r++;
            }
            len=max(len,r-l+1);
        }
        return len-1;
    }
};