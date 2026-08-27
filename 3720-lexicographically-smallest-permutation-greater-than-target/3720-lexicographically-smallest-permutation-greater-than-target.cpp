class Solution {
public:

    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        vector<int> freq(26, 0);

    
        for(char ch : s) {
            freq[ch - 'a']++;
        }

      
        for(int i = 0; i < n; i++) {

            int cur = target[i] - 'a';

            if(freq[cur] > 0) {
                freq[cur]--;
                continue;
            }

           
            for(int c = cur + 1; c < 26; c++) {

                if(freq[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    freq[c]--;

                    for(int x = 0; x < 26; x++) {
                        while(freq[x] > 0) {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }
            }

            

            for(int j = i - 1; j >= 0; j--) {

           
                freq[target[j] - 'a']++;

                int prev = target[j] - 'a';
                for(int c = prev + 1; c < 26; c++) {

                    if(freq[c] > 0) {

                        string ans = target.substr(0, j);

                        ans += char('a' + c);

                        freq[c]--;

                        for(int x = 0; x < 26; x++) {
                            while(freq[x] > 0) {
                                ans += char('a' + x);
                                freq[x]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        for(int i = n - 1; i >= 0; i--) {

         
            freq[target[i] - 'a']++;

            int cur = target[i] - 'a';

            for(int c = cur + 1; c < 26; c++) {

                if(freq[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    freq[c]--;

                    for(int x = 0; x < 26; x++) {
                        while(freq[x] > 0) {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};