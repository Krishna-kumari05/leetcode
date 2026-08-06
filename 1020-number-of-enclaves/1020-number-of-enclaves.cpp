class Solution {
public:
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int i,int j,int drow[],int dcol[]){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=drow[k]+i;
            int ncol=dcol[k]+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                dfs(grid, vis,nrow,ncol,drow,dcol);
            }
        }


    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(grid,vis,0,i,drow,dcol);
            }
             if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(grid,vis,n-1,i,drow,dcol);
            } 
        }
        for(int j =0;j<n;j++){
            if(grid[j][0]==1 && !vis[j][0]){
                dfs(grid,vis,j,0,drow,dcol);
            }
             if(grid[j][m-1]==1 && !vis[j][m-1]){
                dfs(grid,vis,j,m-1,drow,dcol);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};