class Disjoint{
    vector<int>size,parent;
    public:
        Disjoint(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUpar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUpar(parent[node]);
        }
        void Unionbysize(int u,int v){
            int ulpu=findUpar(u);
            int ulpv=findUpar(v);
            if(ulpu==ulpv){
                return;
            }
            if(size[ulpu]<size[ulpv]){
                parent[ulpu]=ulpv;
                size[ulpv]+=size[ulpu];
            }
            else{
                parent[ulpv] = ulpu;
                size[ulpu] += size[ulpv];
}
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        Disjoint ds(maxrow+maxcol+1);
        unordered_map<int,int>stonenodes;
        for(auto it:stones){
            int nrow=it[0];
            int ncol=it[1]+1+maxrow;
            ds.Unionbysize(nrow,ncol);
            stonenodes[nrow]=1;
            stonenodes[ncol]=1;
        }
        int cnt=0;
        for(auto it:stonenodes){
            if(ds.findUpar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};