class Solution {
public:
    vector<vector<string>> ans;

    void dfs(string word, string beginWord,
             unordered_map<string,int> &level,
             vector<string> &path)
    {
        if(word==beginWord)
        {
            vector<string> temp=path;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }

        int currLevel=level[word];

        for(int i=0;i<word.size();i++)
        {
            string temp=word;

            for(char ch='a';ch<='z';ch++)
            {
                temp[i]=ch;

                if(level.find(temp)!=level.end() &&
                   level[temp]==currLevel-1)
                {
                    path.push_back(temp);
                    dfs(temp,beginWord,level,path);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList)
    {

        unordered_set<string> st(wordList.begin(),wordList.end());

        if(st.find(endWord)==st.end())
            return {};

        queue<string> q;

        unordered_map<string,int> level;

        q.push(beginWord);

        level[beginWord]=1;

        st.erase(beginWord);

        while(!q.empty())
        {
            string word=q.front();

            q.pop();

            int currLevel=level[word];

            if(word==endWord)
                break;

            for(int i=0;i<word.size();i++)
            {
                string temp=word;

                for(char ch='a';ch<='z';ch++)
                {
                    temp[i]=ch;

                    if(st.find(temp)!=st.end())
                    {
                        level[temp]=currLevel+1;

                        q.push(temp);

                        st.erase(temp);
                    }
                }
            }
        }

        if(level.find(endWord)==level.end())
            return {};

        vector<string> path;

        path.push_back(endWord);

        dfs(endWord,beginWord,level,path);

        return ans;
    }
};