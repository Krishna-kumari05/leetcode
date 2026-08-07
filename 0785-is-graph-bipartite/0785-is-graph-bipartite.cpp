class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node, int color[], int col)
    {
        vis[node] = 1;
        color[node] = col;

        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                if (!dfs(graph, vis, it, color, 1 - col))
                    return false;
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();

        int color[n];
        fill(color, color + n, -1);

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (!dfs(graph, vis, i, color, 0))
                    return false;
            }
        }

        return true;
    }
};