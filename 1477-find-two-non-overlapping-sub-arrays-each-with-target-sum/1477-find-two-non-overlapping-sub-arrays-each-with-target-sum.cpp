class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        int INF = 1e9;

        
        vector<int> best(n, INF);

       
        unordered_map<int, int> mp;

        mp[0] = -1;

        int prefix = 0;
        int ans = INF;
        int minLen = INF;

        for (int i = 0; i < n; i++) {

            prefix += arr[i];

            if (mp.find(prefix - target) != mp.end()) {

                int j = mp[prefix - target];

                int len = i - j;

                if (j >= 0 && best[j] != INF) {
                    ans = min(ans, len + best[j]);
                }

               
                minLen = min(minLen, len);
            }

        
            best[i] = minLen;

            mp[prefix] = i;
        }

        if (ans == INF)
            return -1;

        return ans;
    }
};