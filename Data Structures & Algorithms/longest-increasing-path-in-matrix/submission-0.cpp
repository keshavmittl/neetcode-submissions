class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i , int j  , vector<vector<int>>&mat){
        
        if(dp[i][j]!= -1 )return dp[i][j];
        int ans = 1 ;

        int delr[] = {-1 ,0 ,1 ,0 };
        int delc[] = {0 ,1 ,0 , -1 };

        for(int k = 0 ;k  <4 ;k++){
            int r = i+ delr[k];
            int c = j + delc[k];

            if(r >=0 && c>=0 && r<mat.size() && c<mat[0].size() && mat[r][c] > mat[i][j]){
                ans= max(ans ,  1 + solve(r , c , mat));
            }
        }
        return dp[i][j] = ans ; 
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 1; 
        dp.assign(n ,vector<int>(m ,-1));
        for(int i = 0 ;i< n ;i++){
            for(int j = 0 ; j< m ;j++ ){
                ans = max(ans , solve(i , j , mat));
            }
        }
        return ans ; 
    }
};
