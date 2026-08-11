class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m=edges.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto it:edges){
            int i=it[0];
            int j=it[1];
            int w=it[2];
            dist[i][j]=w;
            dist[i][j] = w;
            dist[j][i] = w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                dist[i][i]=0;
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int mincnt=1e9;
        int ans=1e9;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
           if(cnt<=mincnt){
                mincnt=cnt;
                ans=i;
           }
        }
        return ans;
    }
};