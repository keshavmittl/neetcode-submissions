class Solution {
public:
    bool ispossible(int rate , vector<int>&piles ,int time  ){
        long long ttaken = 0 ;
        for(int num : piles){
            ttaken += ceil((double)num /rate );
        }
        return ttaken <=time ; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 ; 
        int high = *max_element(piles.begin() ,piles.end());

        int ans=0 ; 
        while(low<=high){
            int mid = (low+ high)/2; 

            if(ispossible(mid , piles ,h )){
                ans = mid ;
                high = mid -1 ;
            }
            else{
                low = mid+1; 
            }
        }
        return ans; 
    }
};
