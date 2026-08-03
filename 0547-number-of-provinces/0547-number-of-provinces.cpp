class Solution {
public:
    vector<int>visited;
    void dfs(int start,vector<vector<int>>& isConnected,int n){
        visited[start]=1;
        for(int j=0;j<n;j++){
            if(isConnected[start][j]==1 && !visited[j]){
               dfs(j,isConnected,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        visited.assign(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected,n);
                cnt++;
            }
        }
        return cnt;
    }
};