class Solution {
public:

    vector<int> findMissingElements(vector<int>& nums) {
        int small=*min_element(nums.begin(),nums.end());
        int large=*max_element(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=small;i<large;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};