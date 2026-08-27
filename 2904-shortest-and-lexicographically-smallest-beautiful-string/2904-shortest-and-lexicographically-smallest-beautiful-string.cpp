class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        int i = 0;
        int cnt = 0;

        int ansl = INT_MAX;
        string ansr = "";

        for(int j = 0; j < n; j++) {

            if(s[j] == '1')
                cnt++;

            while(cnt >= k) {

                if(cnt == k) {

                    int len = j - i + 1;
                    string r = s.substr(i, len);

                    if(len < ansl) {
                        ansl = len;
                        ansr = r;
                    }
                    else if(len == ansl) {
                        ansr = min(ansr, r);
                    }
                }

                
                if(s[i] == '1')
                    cnt--;

                i++;
            }
        }

        return ansr;
    }
};