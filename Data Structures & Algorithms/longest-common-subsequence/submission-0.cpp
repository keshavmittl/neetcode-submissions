class Solution {
public:
vector<vector<int>>dp;
    int solve(int i , int j ,string&s , string & t){
        if(i <  0 || j <0 )return 0 ;
        if(dp[i][j]!= -1 )return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = 1 + solve(i-1 , j-1 , s, t);
        }

        int first = solve(i-1 , j , s, t);
        int second = solve(i , j-1 ,s ,t);

        return dp[i][j] = max(first, second);
        
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m =text2.size();
        dp.assign(n ,vector<int>(m ,-1));
        return solve(n-1 , m-1 , text1 , text2);
    }
};
