class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
             int n=image.size();
        int m=image[0].size();
        int originalcolor = image[sr][sc];
        if(originalcolor==color){
            return image;
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vis[sr][sc]=1;
        image[sr][sc]=color;
        q.push({sr,sc});
       
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
           auto curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int row=drow[i]+curr.first;
                int col=dcol[i]+curr.second;
                if (row >= 0 && row < n &&
                    col >= 0 && col < m &&
                    vis[row][col] != 1 &&
                    image[row][col] == originalcolor) {
                        q.push({row,col});
                        image[row][col]=color;
                }
            }
        }
        return image;
    }
};