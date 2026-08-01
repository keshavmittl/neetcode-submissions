class Solution {

public:
    vector<vector<int>>dp;
    int solve(int i ,int j ,string&s , string&t){
        if(j == t.size())return 1; 
        if(i == s.size()) return 0 ; 

        if(dp[i][j]!= -1 )return dp[i][j];
        int skip = solve(i+1 , j ,s, t);

        int take = 0;

        if(s[i]==t[j]){
            take = solve(i+1 , j+1 , s ,t);
        }
        return  dp[i][j] =  skip+ take; 
    }
    int numDistinct(string s, string t) {
        dp.assign(s.size() ,vector<int>(t.size() , -1));
        return solve(0 , 0 , s, t );
    }
};
