class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        vector<int> freq(10, 0);
        
        // Store frequency of every digit
        for (int d : digits) {
            freq[d]++;
        }
        
        int ans = 0;
        
        for (int num = 100; num <= 998; num++) {
            
            // Number must be even
            if (num % 2 != 0)
                continue;
            
            int x = num;
            
            int a = x % 10;
            x /= 10;
            
            int b = x % 10;
            x /= 10;
            
            int c = x % 10;
            
            // Make a copy because we are checking one number
            vector<int> temp = freq;
            
            if (temp[a] == 0)
                continue;
            temp[a]--;
            
            if (temp[b] == 0)
                continue;
            temp[b]--;
            
            if (temp[c] == 0)
                continue;
            temp[c]--;
            
            ans++;
        }
        
        return ans;
    }
};