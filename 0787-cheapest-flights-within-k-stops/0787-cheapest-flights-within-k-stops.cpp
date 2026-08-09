class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight:flights){
            int node=flight[0];
            int neigh=flight[1];
            int price=flight[2];
            adj[node].push_back({neigh,price});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k){
                continue;
            }
            for(auto l:adj[node]){
                if(cost+l.second<dist[l.first] ){
                    dist[l.first]=cost+l.second;
                
                    q.push({stop+1,{l.first,l.second+cost}});
                }
            }
        }
        if(dist[dst]==1e9){ return -1;
        }
        return dist[dst];
    }
};