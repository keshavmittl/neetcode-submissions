class Solution {
public:
    vector<vector<int>>dp;
    int solve(int start , int end , vector<int>&nums){
        if(start>end)return 0 ;
        if(dp[start][end]!= -1 )return dp[start][end];
        int maxi = -1e9;

        for(int i = start ; i <= end ; i++){
            int coins = nums[start -1 ]* nums[i] * nums[end+1 ] + solve(start , i-1 , nums)
                        + solve(i +1 , end , nums);
            maxi = max(coins , maxi);
        }
        return dp[start][end] = maxi ; 
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() ,1);

        dp.assign(n+2 ,vector<int>(n+2 , -1));
        return solve(1 , n , nums); 
    }
};
