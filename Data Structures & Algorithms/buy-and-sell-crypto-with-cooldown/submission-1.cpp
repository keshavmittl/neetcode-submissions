class Solution {
public:
    vector<vector<int>>dp;
    int solve(int ind , int cap , vector<int>&prices){
        if(ind >= prices.size())return 0 ; 

        if(dp[ind][cap]!= -1 ) return dp[ind][cap];
        int skip = solve(ind +1 , cap , prices);
        int take = 0 ; 
        if(cap){
            take =  solve(ind +1 , 0 , prices) - prices[ind];
        }
        else{
            take = prices[ind] + solve(ind +2 ,1 , prices );
        }

        return dp[ind][cap] = max(take ,skip);
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size() , vector<int>(2 , -1 ));
        return solve(0 , 1 , prices);
    }
};
