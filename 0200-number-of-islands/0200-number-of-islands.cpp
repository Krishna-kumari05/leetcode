class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,int drow[],int dcol[]){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=drow[k]+i;
            int ncol=dcol[k]+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && grid[nrow][ncol]=='1'){
                dfs(grid, vis,nrow,ncol,drow,dcol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,vis,i,j,drow,dcol);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};