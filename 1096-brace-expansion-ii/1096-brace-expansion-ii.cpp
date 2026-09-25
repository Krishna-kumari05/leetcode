class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        set<string> ans = solve(expression, pos);
        
        return vector<string>(ans.begin(), ans.end());
    }

    set<string> solve(string &s, int &pos) {
        set<string> result;
        set<string> current;
        current.insert("");

        while (pos < s.size() && s[pos] != '}') {
            
            if (s[pos] == '{') {
                pos++; 
                
                set<string> inside = solve(s, pos);
                pos++; 
                
                set<string> temp;
                
       
                for (string a : current) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }
                
                current = temp;
            }
            
            else if (s[pos] == ',') {
        
                result.insert(current.begin(), current.end());
                
                current.clear();
                current.insert("");
                
                pos++;
            }
            
            else {
         
                char ch = s[pos];
                
                set<string> temp;
                
                for (string x : current) {
                    temp.insert(x + ch);
                }
                
                current = temp;
                pos++;
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }
};