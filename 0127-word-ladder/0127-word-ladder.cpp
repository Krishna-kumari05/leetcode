class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        int cnt=1;
        q.push({beginWord,cnt});
        int s=beginWord.size();
        while (!q.empty()) {
            string word = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (word == endWord)
                return cnt;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (st.find(temp) != st.end()) {
                        st.erase(temp);
                        q.push({temp, cnt + 1});
                    }
                }
    }
}
        return 0;
    }
};