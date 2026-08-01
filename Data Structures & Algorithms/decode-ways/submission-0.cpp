class Solution {
public: 
    int solve(int ind , string s ,vector<int>&dp){
        if(ind == s.size()) return 1 ; 

        if(s[ind]=='0')return 0 ;
        if(dp[ind]!= -1)return dp[ind];
        int one = solve(ind+1 , s ,dp);
        int two = 0;
        if(ind+1 < s.size()){
            int num = (s[ind]-'0')*10 + s[ind+1] -'0';

            if(num<27)
            two = solve(ind+2 , s  ,dp) ;
        }
        return dp[ind]= one+two; 
    }
    int numDecodings(string s) {
        vector<int>dp(s.size() , -1);
        return solve( 0 , s ,dp);
    }
};
