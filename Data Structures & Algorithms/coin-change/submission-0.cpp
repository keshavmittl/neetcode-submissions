class Solution {
public:
    int solve(int ind ,vector<int>&coins , int target , vector<vector<int>>&dp){
        if(ind == coins.size()-1 ){
            if(target%coins[ind] == 0){
                return target /coins[ind];
            }
            return 1e9;
        }

        if(dp[ind][target] != -1 )return dp[ind][target];
        int skip = solve(ind +1 , coins ,target , dp);
        int take =1e9 ; 
        if(target>= coins[ind]){
            take = 1 +solve(ind , coins ,target - coins[ind] ,dp);
        }

        return dp[ind][target] = min(skip , take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size() ,vector<int>(amount +1  , -1 ));
        int ans = solve(0 , coins, amount ,dp);

        if(ans >= 1e9)return -1 ;
        return ans; 
    }
};
