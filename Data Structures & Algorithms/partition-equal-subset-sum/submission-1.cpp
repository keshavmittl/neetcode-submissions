class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int ind ,vector<int>&nums ,int target){
        if(ind == nums.size()){
            if(target ==0 )return true;
            return false; 
        }
        if(dp[ind][target] != -1 )return dp[ind][target];
        bool skip = solve(ind+1 ,nums , target);
        bool take = false; 
        if(target>= nums[ind]){
            take = solve(ind+ 1 , nums ,target -nums[ind]);
        }

        return dp[ind][target] = skip|| take ;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i = 0 ;i<nums.size() ;i++)sum+=nums[i];
        if(sum%2) return false;
        dp.resize(nums.size() ,vector<int>(sum/2 +1 , -1));
        return solve(0 , nums , sum/2);
    }
};
