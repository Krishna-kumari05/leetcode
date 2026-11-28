
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = INT_MAX;
        vector<int> freq(n + 1, 0);

        for (auto &x : items) {
            freq[x[0]]++;
            mn = min(mn, x[1]);
        }

        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i)
                gain[i] += freq[j];
            gain[i]--;
        }

        sort(items.begin(), items.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        long long ans = 0, rem = budget;

        for (auto &x : items) {
            int f = x[0], p = x[1];

            if (p >= 2LL * mn) break;

            long long take = min((long long)gain[f], rem / p);

            ans += 2 * take;
            rem -= take * p;
        }

        ans += rem / mn;

        return (int)ans;
    }
};
