class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> bit(n + 2, 0);
        int timer = 0;

        auto add = [&](int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto sum = [&](int i) {
            int ans = 0;
            for (; i > 0; i -= i & -i)
                ans ^= bit[i];
            return ans;
        };

        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        // Iterative DFS to avoid stack overflow.
        vector<int> parent(n, -1), order;
        vector<int> st = {0};
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = ++timer;
            order.push_back(u);
            up[0][u] = parent[u];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++)
                up[k][u] = up[k - 1][up[k - 1][u]];
        }

        // Calculate subtree exit times.
        for (int u = 0; u < n; u++)
            tout[u] = tin[u];

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            if (u != 0)
                tout[parent[u]] = max(tout[parent[u]], tout[u]);
        }

        // Insert each node's character into its subtree range.
        for (int u = 0; u < n; u++) {
            rangeXor(tin[u], tout[u], 1 << (s[u] - 'a'));
        }

        auto getMask = [&](int u) {
            return sum(tin[u]);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string &q : queries) {
            string type, c;
            int u, v;

            stringstream ss(q);
            ss >> type >> u >> c;

            if (type == "update") {
                char ch = c[0];

                int change = (1 << (s[u] - 'a'))
                           ^ (1 << (ch - 'a'));

                rangeXor(tin[u], tout[u], change);
                s[u] = ch;
            } else {
                v = stoi(c);
                int w = lca(u, v);

                int mask = getMask(u) ^ getMask(v)
                         ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};