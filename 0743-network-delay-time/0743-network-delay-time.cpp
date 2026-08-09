class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        //time , next node
        for(auto time : times) {
            int start = time[0];
            int target = time[1];
            int t= time[2];

            adj[start].push_back({target,t});
        }
       priority_queue<pair<int,int>,
               vector<pair<int,int>>,       //time,node
               greater<pair<int,int>>> q;
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int t=it.first;
            int node=it.second;
            for(auto l:adj[node]){
                int nextnode=l.first;
                int t1=l.second;
                if(t+t1<dist[nextnode]){
                    dist[nextnode]=t+t1;
                    q.push({t+t1,nextnode});
                }
            }
        }
        int maxi=0;
        for (int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            maxi=max(maxi,dist[i]);
        }
    
        return maxi;
    }
};