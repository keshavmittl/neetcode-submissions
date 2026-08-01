class Solution {
public:
    int solve(int ind , int n , vector<int>&dp){

        if(ind == 0 )return 0 ;
        if(ind == 1) return 1; 
        if(ind == 2 )return 1; 
        if(dp[ind] != -1 )return dp[ind];
        int num = solve(ind-1 , n , dp) +solve(ind -2 , n ,dp) + solve(ind -3 ,n ,dp);

        return dp[ind] = num;
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return solve( n, n ,dp );
    }
};