class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0 ;
        int maxi = -1e9;
        int mini = 1e9;
        int currmax = 0 ; 
        int currmin = 0 ;

        for(int x : nums){
            total += x ;

            currmax = max(x , x + currmax);
            maxi = max(maxi , currmax);

            currmin = min(x ,  x+ currmin);
            mini = min(mini, currmin);
        }
        if(maxi < 0 )return maxi ;

        return max(maxi , total - mini); 
    }
};