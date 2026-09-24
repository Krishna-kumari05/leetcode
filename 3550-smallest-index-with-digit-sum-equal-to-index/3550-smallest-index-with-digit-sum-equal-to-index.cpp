class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=nums[i];
            int sum=0;
            while(k>0){
                int m=k%10;
                sum+=m;
                k=k/10;
            }
            if(i==sum){
                return i;
            }
        }
        return -1;
    }
}; 