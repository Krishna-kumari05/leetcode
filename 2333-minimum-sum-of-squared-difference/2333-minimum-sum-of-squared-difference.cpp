
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int maxi = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
            total += diff[i];
        }

        if (k >= total) {
            return 0;
        }

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            if (d > level) {
                used += d - level;
                ans += 1LL * level * level;
            } else {
                ans += 1LL * d * d;
            }
        }

        long long remaining = k - used;

        // Reduce remaining differences one more step,
        // starting with those equal to level.
        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= level && d > 0) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                remaining--;
            }
        }

        return ans;
    }
};