class Solution {
public:
vector<vector<int>>dp;
    bool solve(int ind , int target , vector<int>&stone){
        if(target == 0) return true ;
        if(ind >= stone.size())return false ;

        if(dp[ind][target]!= -1 )return dp[ind][target];

        bool skip = solve(ind +1 , target , stone);

        bool take = false; 

        if(target>= stone[ind]){
            take = solve(ind + 1 ,target - stone[ind] , stone);
        }

        return dp[ind][target] =skip || take ;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0 ; 
        for(int num : stones) total+=num;

        int target = total/2 ;
        dp.assign(stones.size() , vector<int>(target +1 , -1));

        for(int i = target ; i>=0 ; i-- ){
            bool ispresent =  solve(0 , i, stones);

            if(ispresent == true){
                return total - 2* i ;
            }

        }
        return 0 ; 
    }
};