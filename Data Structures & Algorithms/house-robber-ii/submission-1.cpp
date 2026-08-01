class Solution {
public:
    int solve(int ind , vector<int>&nums ,int n , vector<int>&dp){
        if(ind>=n) return 0;
        if(dp[ind] != -1 )return dp[ind];
        int r = nums[ind]+ solve(ind+2 , nums , n,dp);
        int l = solve(ind+1 ,nums, n ,  dp);

        return dp[ind] = max(r, l);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() ,-1);
        vector<int>dp2(nums.size() ,-1);
        int n = nums.size();
        if(n ==1 )return nums[0];
        return max(solve(0 , nums, n-1,  dp) ,solve(1 , nums ,n ,dp2));
    }
};
