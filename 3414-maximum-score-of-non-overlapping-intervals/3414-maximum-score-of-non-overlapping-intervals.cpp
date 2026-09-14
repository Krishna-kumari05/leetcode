class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        // {start, end, weight, original index}
        vector<vector<long long>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending time
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        // dp[i][k] = {maximum weight, indices}
        // first i intervals, selecting at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int i = 1; i <= n; i++) {

            long long start = a[i - 1][0];
            long long weight = a[i - 1][2];
            int index = a[i - 1][3];

            // Find previous interval whose end < current start
            int low = 0;
            int high = i - 2;
            int prev = -1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (a[mid][1] < start) {
                    prev = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            for (int k = 1; k <= 4; k++) {

                // Don't take current interval
                dp[i][k] = dp[i - 1][k];

                // Take current interval
                pair<long long, vector<int>> take;

                take.first = weight;
                take.second.push_back(index);

                if (prev != -1) {
                    take.first += dp[prev + 1][k - 1].first;

                    for (int x : dp[prev + 1][k - 1].second) {
                        take.second.push_back(x);
                    }
                }

                // Compare
                sort(take.second.begin(), take.second.end());

                if (take.first > dp[i][k].first) {
                    dp[i][k] = take;
                }
                else if (take.first == dp[i][k].first &&
                         take.second < dp[i][k].second) {
                    dp[i][k] = take;
                }
            }
        }

        return dp[n][4].second;
    }
};