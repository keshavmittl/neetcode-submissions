class Solution {
   public:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        vis[i][j] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int r = i + dr[k];
            int c = j + dc[k];

            if (r >= 0 && r < heights.size() && c >= 0 && c < heights[0].size() && !vis[r][c] &&
                heights[r][c] >= heights[i][j]) {
                dfs(r, c, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific: left column
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);
        }

        // Pacific: top row
        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);
        }

        // Atlantic: right column
        for (int i = 0; i < n; i++) {
            dfs(i, m - 1, heights, atlantic);
        }

        // Atlantic: bottom row
        for (int j = 0; j < m; j++) {
            dfs(n - 1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};