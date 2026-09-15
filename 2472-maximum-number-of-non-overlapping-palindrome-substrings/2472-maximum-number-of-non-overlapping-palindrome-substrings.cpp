class Solution {
public:
    int maxPalindromes(string s, int k) {
        
        int n = s.size();

        vector<int> dp(n + 1, 0);

        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            
            for (int i = 0; i + len - 1 < n; i++) {
                
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    
                    if (len <= 2) {
                        palindrome[i][j] = true;
                    }
                    else {
                        palindrome[i][j] = palindrome[i + 1][j - 1];
                    }
                }
            }
        }

       
        for (int i = 1; i <= n; i++) {
         
            dp[i] = dp[i - 1];

            for (int start = 0; start < i; start++) {
                
                if (i - start >= k && palindrome[start][i - 1]) {
                    
                    dp[i] = max(dp[i], dp[start] + 1);
                }
            }
        }

        return dp[n];
    }
};