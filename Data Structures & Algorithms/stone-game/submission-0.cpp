class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int left = 0 ;
        int right = n-1;
        int sum1 = 0 ;
        int sum2 = 0 ;
        bool flag = true; //for alice
        while(left<=right){
            if(flag){
               if(piles[left] > piles[right]){
                    sum1+= piles[left];
                    left++;
               }
               else{
                    sum1+=piles[right];
                    right--;
               }   
            }
            else{
                if(piles[left] > piles[right]){
                    sum2+= piles[left];
                    left++;
               }
               else{
                    sum2+=piles[right];
                    right--;
               }   
            }
        }
        return sum1 > sum2;
    }
};