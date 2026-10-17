
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        sort(v.begin(), v.end());

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i) {
                continue;
            }

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = 1;
                j = v[j].second;
                cycle++;
            }

            if (cycle > 0) {
                ans += cycle - 1;
            }
        }

        return ans;
    }
};
