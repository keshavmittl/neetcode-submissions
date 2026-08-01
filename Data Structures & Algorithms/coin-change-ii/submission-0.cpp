class Solution {
public:
vector<vector<int>>dp;
    int solve(int ind , int target , vector<int>& coins){
        if(target == 0 )return 1 ; 
        if(ind == coins.size() -1 ){
            if(target%coins[ind] ==0 )return 1 ;
            return 0 ;
        }

        if(dp[ind][target]!= -1 )return dp[ind][target];
        int skip = solve(ind +1 ,target ,coins);
        int take = 0 ;

        if(target>= coins[ind]){
            take = solve(ind , target - coins[ind] , coins);
        }
        return dp[ind][target] = take+ skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n ,vector<int>(amount+ 1 , -1 ));
        return solve(0 ,amount , coins);
    }
};
