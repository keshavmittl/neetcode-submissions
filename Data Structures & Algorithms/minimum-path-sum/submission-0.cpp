class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i ,int j , vector<vector<int>>&grid){
        if(i == 0 && j ==0 )return grid[0][0];
        if(i<0 || j< 0 )return 1e9 ;

        if(dp[i][j]!= -1 )return dp[i][j];
        int left = solve(i , j-1 ,grid);
        int up = solve(i- 1 , j , grid);

        return dp[i][j] = grid[i][j] + min(left ,up) ;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        dp.assign(n ,vector<int>(m,-1));
        return  solve( n-1 , m-1,grid);
    }
};