
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        // Build directed graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][count]
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        // {cost, node, consecutive count}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        // Starting node has count 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt])
                continue;

            // Destination reached
            if (u == n - 1)
                return cost;

            for (auto &p : adj[u]) {

                int v = p.first;
                int wt = p.second;

                int newCnt;

                if (labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                // Cannot have more than k identical characters
                if (newCnt > k)
                    continue;

                long long newCost = cost + wt;

                if (newCost < dist[v][newCnt]) {

                    dist[v][newCnt] = newCost;

                    pq.push({newCost, v, newCnt});
                }
            }
        }

        return -1;
    }
};
