class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,int node,vector<int>& ans){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,pathvis,it,ans))
                    return true;
            }
            else if(pathvis[it]){
                return true;
            }

        }
        pathvis[node]=0;
        ans.push_back(node);
        return false;

    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int >vis(numCourses,0);
        for(auto it:prerequisites){
            int  i=it[0];
            int j=it[1];
            adj[j].push_back(i);

        }
      
        vector<int> pathvis(numCourses, 0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,vis,pathvis,i,ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};