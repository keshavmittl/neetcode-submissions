class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;//stores sum adn freq
        int  sum = 0 ; 
        int total = 0 ;
        for(int num :nums){
            sum+= num;

            if(sum == k ){
                total++;
            }
            if(mp.count(sum- k)){
                total +=mp[sum-k];
            }
            mp[sum]++;
        }
        return total ;
    }
};