class Solution {
public:
vector<vector<int>>dp;
    int solve(int i , int j ){
        if(i == 0 && j == 0 )return 1 ;
        if(i<0  || j < 0 )return 0 ; 
        if(dp[i][j] != -1 )return dp[i][j];
        int left = solve(i , j -1 );
        int up = solve(i -1 , j );

        return dp[i][j] = left+ up;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m ,vector<int>(n , -1));
        return solve(m-1 , n-1 );
    }
};
