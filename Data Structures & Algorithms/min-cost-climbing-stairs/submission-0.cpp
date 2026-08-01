class Solution {
public:
    int solve(int ind , vector<int>&cost ,vector<int>&dp){
        if(ind >= cost.size()) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int single = solve(ind +1 , cost , dp) ;
        int twice =solve(ind +2 , cost ,dp);

        return dp[ind] = cost[ind]+min(single ,twice);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <=1 )return 0;
        int n =cost.size();
        vector<int>dp(n,-1);
        return min(solve(0 , cost , dp), solve(1, cost, dp));
    }
};
