class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1)
            return {0};

        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int mini = INT_MAX;
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            queue<int> q;
            vector<int> vis(n, 0);

            q.push(i);
            vis[i] = 1;

            int height = -1;

            while (!q.empty()) {

                int sz = q.size();

                while (sz--) {

                    int node = q.front();
                    q.pop();

                    for (int neigh : adj[node]) {
                        if (!vis[neigh]) {
                            vis[neigh] = 1;
                            q.push(neigh);
                        }
                    }
                }

                height++;
            }

            if (height < mini) {
                mini = height;
                ans.clear();
                ans.push_back(i);
            }
            else if (height == mini) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};