class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        set<int>s(nums.begin(),nums.end());
       
        for(int i=1;i<=101;i++){
            if(s.find(k*i)==s.end()){
                return k*i;
            }
        }
        return 0;
        
    }
};