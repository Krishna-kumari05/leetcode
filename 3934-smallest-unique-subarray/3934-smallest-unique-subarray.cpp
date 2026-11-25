
class Solution {
public:

    const long long mod1 = 1000000007;
    const long long mod2 = 1000000009;

    const long long base1 = 100003;
    const long long base2 = 100019;

    bool check(int len, vector<int>& nums) {
        int n = nums.size();

        long long power1 = 1;
        long long power2 = 1;
        for (int i = 0; i < len; i++) {
            power1 = (power1 * base1) % mod1;
            power2 = (power2 * base2) % mod2;
        }

        long long h1 = 0, h2 = 0;

        for (int i = 0; i < len; i++) {
            h1 = (h1 * base1 + nums[i]) % mod1;
            h2 = (h2 * base2 + nums[i]) % mod2;
        }

        unordered_map<unsigned long long, int> mp;

        auto getKey = [&]() {
            return ((unsigned long long)h1 << 32) |
                   (unsigned long long)h2;
        };

        mp[getKey()]++;

        for (int i = len; i < n; i++) {

            h1 = (h1 * base1 -
                  (power1 * nums[i - len]) % mod1
                  + nums[i] + mod1) % mod1;

            h2 = (h2 * base2 -
                  (power2 * nums[i - len]) % mod2
                  + nums[i] + mod2) % mod2;

            mp[getKey()]++;
        }

        for (auto it : mp) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
