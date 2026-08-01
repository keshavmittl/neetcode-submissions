class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore voting
        int cnt = 0 ; 
        int val = 0 ; 
        for(int i = 0 ;i<nums.size() ;i++){
            if(cnt == 0 ){
                cnt ++;
                val = nums[i];
            }

            if(nums[i] == val){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return val ;
    }
};