class Solution {
public:
    void dfs(vector<vector<int>>&vis,vector<vector<char>>&board,int row,int col,int drow[],int dcol[]){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            
           int nrow=row+drow[i];
           int ncol=col+dcol[i];
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
            dfs(vis,board,nrow,ncol,drow,dcol);
           }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis;
        int n=board.size();
        int m=board[0].size();
        vis.assign(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(vis,board,0,j,drow,dcol);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(vis,board,n-1,j,drow,dcol);
            }
        }
        for(int j=0;j<n;j++){
            if(board[j][0]=='O' && !vis[j][0]){
                dfs(vis,board,j,0,drow,dcol);
            }
            if(board[j][m-1]=='O' && !vis[j][m-1]){
                dfs(vis,board,j,m-1,drow,dcol);
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};