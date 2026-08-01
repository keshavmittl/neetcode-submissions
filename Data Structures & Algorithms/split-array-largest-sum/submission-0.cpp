class Solution {
public:
    bool ispossible(int cap , vector<int>&nums , int total){
        int curr= 0 ;
        int k = 1;
        for(int num : nums){
            if(curr + num <= cap){
                curr+=num;
            }
            else{
                curr = num ;
                k++;
            }
        }
        return k<=total; 
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin() ,nums.end());
        int high = accumulate(nums.begin() ,nums.end() ,0);
        int ans = 0 ; 
        while(low<=high){
            int mid = (low+high)/2; 

            if(ispossible(mid ,nums, k)){
                ans =mid; 
                high = mid -1 ;
            }
            else{
                low =mid +1; 
            }
        }
        return ans ;
    }
};