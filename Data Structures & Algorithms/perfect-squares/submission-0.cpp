class Solution {
public:
    vector<vector<int>>dp;  
    int solve(int ind , int target , vector<int>&sq){
        if(ind == sq.size())return 1e9;
        if(target == 0){
            return 0 ; 
        }
        if(dp[ind][target]!= -1 )return dp[ind][target];
        int skip = solve(ind +1 , target, sq);

        int take =1e9 ;

        if(target >= sq[ind]){
            take = 1 +solve(ind , target- sq[ind] , sq);
        }

        return  dp[ind][target]=min(take ,skip);
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i = 1; i*i <= n ; i++){
            sq.push_back(i*i);
        }
        dp.resize(sq.size() , vector<int>(n+1 , -1));
        return solve(0 , n , sq);
    }
};