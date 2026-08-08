class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathvis,int node,vector<int>&ans){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(graph,vis,pathvis,it,ans)){     //m if there is a cycle it will be break down here 
                    return true;
                }
            }
            else if(pathvis[it]){
                    return true;           // or here 
                }
        }

        ans.push_back(node);
        pathvis[node]=0;                // so we include nodes that are ssafe here ,here means dfs comppleted 
        return false;                       // successfully with no cycles 

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,vis,pathvis,i,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};