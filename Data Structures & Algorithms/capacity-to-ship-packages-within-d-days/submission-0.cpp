class Solution {
   public:
    bool ispossible(int cap , vector<int>&nums ,int mdays){
        int days =1 ;
        int curr = 0 ; 
        for(int num : nums){
            if(curr + num <= cap){
                curr+=num;
            }
            else{
                curr = num ;
                days++;
            }
        }
        return days<=mdays;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans= -1; 
        while (low <= high) {
            int mid = (low + high) / 2;

            if (ispossible(mid, nums, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans ;
    }
};