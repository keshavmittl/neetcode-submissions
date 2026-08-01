class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //use kadane algo
        int sum = 0 ; 
        int maxi = -1e9;
        for(int num : nums){
            if(sum <0 )sum = 0 ;
            sum+=num;

            maxi = max(sum , maxi);
        }
        return maxi;
    }
};
