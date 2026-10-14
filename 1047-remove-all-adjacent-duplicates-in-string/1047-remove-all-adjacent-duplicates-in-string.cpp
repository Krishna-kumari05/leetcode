class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string k = "";
        while (!st.empty()) {
            k += st.top();
            st.pop();
        }
        reverse(k.begin(), k.end());
        return k;
    }
};