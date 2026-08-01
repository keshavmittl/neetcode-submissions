class Solution {
public:
    int solve(int ind, int n , vector<int>&dp){
        if(ind>n) return 0;
        if(ind == n )return 1; 
        if(dp[ind]!= -1 )return dp[ind];
        int single = solve(ind+1 , n , dp);
        int twice = solve(ind+2 , n , dp);

        return dp[ind] = single+twice; 
    }
    int climbStairs(int n) {
        vector<int>dp(n, -1);
        return solve(0 , n , dp);
    }
};
