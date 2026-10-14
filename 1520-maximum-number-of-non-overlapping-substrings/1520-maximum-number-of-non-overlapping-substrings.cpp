
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);


        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<string> ans;
        int end = -1;

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

          
            if (i != first[c]) {
                continue;
            }

            int right = last[c];
            bool valid = true;

            for (int j = i; j <= right; j++) {
                int x = s[j] - 'a';

                if (first[x] < i) {
                    valid = false;
                    break;
                }

                right = max(right, last[x]);
            }

            if (valid) {
                if (i > end) {
                    ans.push_back(s.substr(i, right - i + 1));
                } else {
                    ans.back() = s.substr(i, right - i + 1);
                }

                end = right;
            }
        }

        return ans;
    }
};
