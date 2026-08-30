class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();

        int m = nums.size();

        
        int left = min(mini, maxi);
        int right = max(mini, maxi);


        int option1 = right + 1;

    
        int option2 = m - left;

     
        int option3 = (left + 1) + (m - right);

        return min({option1, option2, option3});
    }
};