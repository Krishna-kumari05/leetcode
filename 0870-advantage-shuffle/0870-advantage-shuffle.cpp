class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        vector<pair<int,int>> b;

        for(int i=0;i<n;i++)
            b.push_back({nums2[i], i});

        sort(b.begin(), b.end());

        vector<int> ans(n);

        int low = 0;
        int high = n - 1;

        for(int i=n-1;i>=0;i--) {

            if(nums1[high] > b[i].first) {
                ans[b[i].second] = nums1[high];
                high--;
            }
            else {
                ans[b[i].second] = nums1[low];
                low++;
            }
        }

        return ans;
    }
};