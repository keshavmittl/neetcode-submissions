class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // Path compression
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return false;

        // Attach smaller tree to larger tree
        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];

        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());

        for (auto &e : edges) {
            if (!dsu.unite(e[0], e[1]))
                return e;
        }

        return {};
    }
};