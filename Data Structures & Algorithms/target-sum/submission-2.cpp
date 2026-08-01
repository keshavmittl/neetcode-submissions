class Solution {
public:
    int offset;
    vector<vector<int>>dp;
    int solve(int ind ,int sum , int target , vector<int>&nums){
        if(ind == nums.size()){
            return sum == target;
        }
        if(dp[ind][sum+offset]!= -1 ) return dp[ind][sum+offset];
        int posi = solve(ind +1 , sum + nums[ind] , target , nums);
        int neg = solve(ind +1 , sum - nums[ind] ,target,  nums);

        return dp[ind][sum+offset]= posi + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0 ; 
        for (int x : nums)
            total += x;
        offset = total ; 
        dp.assign(n , vector<int>(2*total + 1 , -1 ));
        return solve( 0 ,0 , target ,nums);
    }
};
