class Solution {
public:
    const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }

    long long nCr(int n, int r, vector<long long>& fact,
                  vector<long long>& invFact) {
        if (r < 0 || r > n)
            return 0;

        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countValidSequences(int n, int k) {

        int LIMIT = 2 * n;

        vector<long long> fact(LIMIT + 1);
        vector<long long> invFact(LIMIT + 1);

        fact[0] = 1;

        for (int i = 1; i <= LIMIT; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[LIMIT] = power(fact[LIMIT], MOD - 2);

        for (int i = LIMIT - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        long long total = nCr(n - 1, k - 1, fact, invFact);

        long long odd = 0;

        if ((n - k) % 2 == 0) {
            int m = (n + k - 2) / 2;
            odd = nCr(m, k - 1, fact, invFact);
        }

        return (total - odd + MOD) % MOD;
    }
};