class Solution {
public:
    int dfs(int i , int j ,vector<vector<int>>&vis ,vector<vector<int>>&grid){
        vis[i][j] =1 ;
        int delr[] = {0 ,1, 0 ,-1 };
        int delc[] = {1, 0 ,-1 , 0 };
        int area = 1 ;
        for(int k = 0 ;k<4 ;k++){
            int r =i+ delr[k];
            int c= j + delc[k];

            if(r>=0 && c>=0 && r<grid.size()  && c < grid[0].size() &&grid[r][c] == 1 && !vis[r][c]){
                 area += dfs(r ,c ,vis , grid);
            }
        }
        return area; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int maxi = 0 ; 
        vector<vector<int>>vis(n ,vector<int>(m, 0));
        for(int i = 0 ; i< n ;i++ ){
            for(int j = 0 ; j< m ;j++){
                if(grid[i][j] ==1  && !vis[i][j] ){
                    int area = dfs(i , j , vis , grid);
                    maxi = max(maxi , area);
                }
            }
        }
        return maxi; 
    }
};
