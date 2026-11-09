
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish time, server number}
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> busy;

        vector<int> cnt(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Free servers whose requests are completed
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            if(available.empty())
                continue;

            int preferred = i % k;

            // Find first available server >= preferred
            auto it = available.lower_bound(preferred);

            // If not found, wrap around to the first server
            if(it == available.end())
                it = available.begin();

            int server = *it;

            available.erase(it);

            cnt[server]++;

            // Mark server as busy
            busy.push({arrival[i] + load[i], server});
        }

        // Find maximum requests handled
        int maxi = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(cnt[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
