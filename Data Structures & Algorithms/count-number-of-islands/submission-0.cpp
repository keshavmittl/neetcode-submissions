class Solution {
public:
    void dfs(int i , int j ,vector<vector<int>>&vis ,vector<vector<char>>&grid){
        vis[i][j] =1 ;
        int delr[] = {0 ,1, 0 ,-1 };
        int delc[] = {1, 0 ,-1 , 0 };

        for(int k = 0 ;k<4 ;k++){
            int r =i+ delr[k];
            int c= j + delc[k];

            if(r>=0 && c>=0 && r<grid.size()  && c < grid[0].size() &&grid[r][c] == '1' && !vis[r][c]){
                dfs(r ,c ,vis , grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int cnt = 0 ; 
        vector<vector<int>>vis(n ,vector<int>(m, 0));
        for(int i = 0 ; i< n ;i++ ){
            for(int j = 0 ; j< m ;j++){
                if(grid[i][j] =='1' && !vis[i][j] ){
                    dfs(i , j , vis , grid);
                    cnt++;
                }
            }
        }
    return cnt; 
    }
};
