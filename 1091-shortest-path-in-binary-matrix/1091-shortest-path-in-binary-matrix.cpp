class Solution {
public:
    int  bfs(vector<vector<int>>grid,int drow[],int dcol[] , vector<vector<int>>&vis){
        queue<pair<pair<int,int>,int>>q;
        vis[0][0]=1;
        q.push({{0,0},1});
         int n=grid.size();
        int m=grid[0].size();
        int cnt=1;
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            auto k=it.first;
            int b=it.second;
            if(k.first == n-1 && k.second == m-1)
                 return b;

            for(int l=0;l<8;l++){
                if(k.first+drow[l]>=0 && k.first+drow[l] <n && k.second+ dcol[l]>=0 && k.second+ dcol[l]<m && !vis[k.first+drow[l]][k.second+dcol[l]]  && grid[k.first+drow[l]][k.second+dcol[l]]==0){
                    q.push({{k.first+drow[l],k.second+dcol[l]},b+1});
                    vis[k.first+drow[l]][k.second+dcol[l]]=1;

                }
            }
        }

        return -1;

    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
       
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;
        return (bfs(grid, dcol,drow,vis));
    }
};