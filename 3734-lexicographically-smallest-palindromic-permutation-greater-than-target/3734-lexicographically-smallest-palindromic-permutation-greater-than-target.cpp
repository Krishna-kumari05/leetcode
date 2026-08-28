class Solution {
public:

    string makePalindrome(string left, char mid) {
        string right = left;
        reverse(right.begin(), right.end());

        return left + (mid ? string(1, mid) : "") + right;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        vector<int> cnt(26, 0);

        for(char c : s)
            cnt[c - 'a']++;


        int odd = 0;
        char mid = 0;

        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if(odd > 1)
            return "";

        
        vector<int> halfCnt(26, 0);

        for(int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int half = n / 2;

        string targetLeft = target.substr(0, half);

        
        vector<int> temp = halfCnt;
        bool possible = true;

        for(char c : targetLeft) {
            if(temp[c - 'a'] == 0) {
                possible = false;
                break;
            }

            temp[c - 'a']--;
        }

        if(possible) {

            string candidate = makePalindrome(targetLeft, mid);

            if(candidate > target)
                return candidate;
        }


        vector<int> remaining = halfCnt;

       
        for(int i = 0; i < half; i++) {

            int x = targetLeft[i] - 'a';

            if(remaining[x] == 0)
                break;

            remaining[x]--;
        }

        remaining = halfCnt;

        for(int i = 0; i < half; i++) {

            int x = targetLeft[i] - 'a';

            if(remaining[x] == 0)
                break;

            remaining[x]--;
        }

        for(int pivot = half - 1; pivot >= 0; pivot--) {

            vector<int> rem = halfCnt;

            bool ok = true;

            for(int i = 0; i < pivot; i++) {

                int x = targetLeft[i] - 'a';

                if(rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
            }

            if(!ok)
                continue;

            int cur = targetLeft[pivot] - 'a';

       
            for(int c = cur + 1; c < 26; c++) {

                if(rem[c] == 0)
                    continue;

                string left = targetLeft.substr(0, pivot);

                left += char('a' + c);

                rem[c]--;

                
                for(int k = 0; k < 26; k++) {
                    while(rem[k] > 0) {
                        left += char('a' + k);
                        rem[k]--;
                    }
                }

                return makePalindrome(left, mid);
            }
        }

        return "";
    }
};