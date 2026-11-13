
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        deque<pair<int, int>> dq;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int count = 1;

            // Merge smaller elements
            while (!dq.empty() && dq.back().first < num) {

                int nextNum = dq.back().first;
                int nextCount = dq.back().second;

                dq.pop_back();

                count += nextCount;

                cost += 1LL * (num - nextNum) * nextCount;
            }

            dq.push_back({num, count});

            // Shrink window if cost exceeds k
            while (cost > k) {

                int rightNum = dq.front().first;
                int rightCount = dq.front().second;

                dq.pop_front();

                cost -= (rightNum - nums[j]);
                j--;

                if (rightCount > 1) {
                    dq.push_front({rightNum, rightCount - 1});
                }
            }

            // Count valid subarrays
            ans += (j - i + 1);
        }

        return ans;
    }
};
