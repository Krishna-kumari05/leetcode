class Solution {
public:

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(vector<int>& coins, long long x) {

        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++) {

            long long LCM = 1;
            int bits = 0;
            bool tooLarge = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                 
                    long long g = gcd(LCM, (long long)coins[i]);

                    LCM = LCM / g * coins[i];

                    if (LCM > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            long long current = x / LCM;

            if (bits % 2 == 1)
                count += current;
            else
                count -= current;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countNumbers(coins, mid) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};