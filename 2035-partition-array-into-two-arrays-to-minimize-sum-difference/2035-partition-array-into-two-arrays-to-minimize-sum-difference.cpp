class Solution {
public:

    void generate(vector<int>& arr, vector<vector<int>>& sums) {

        int n = arr.size();

        for(int mask = 0; mask < (1 << n); mask++) {

            int sum = 0;
            int count = 0;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {
                    sum += arr[i];
                    count++;
                }
            }

            sums[count].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {

        int N = nums.size();
        int n = N / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> leftSums(n + 1);
        vector<vector<int>> rightSums(n + 1);

        generate(left, leftSums);
        generate(right, rightSums);

        for(int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0);

        int ans = INT_MAX;

        for(int cnt = 0; cnt <= n; cnt++) {

            int other = n - cnt;

            for(int x : leftSums[cnt]) {

                int target = total / 2 - x;

                auto it = lower_bound(
                    rightSums[other].begin(),
                    rightSums[other].end(),
                    target
                );

          
                if(it != rightSums[other].end()) {

                    int sum1 = x + *it;

                    ans = min(ans, abs(total - 2 * sum1));
                }

             
                if(it != rightSums[other].begin()) {

                    --it;

                    int sum1 = x + *it;

                    ans = min(ans, abs(total - 2 * sum1));
                }
            }
        }

        return ans;
    }
};