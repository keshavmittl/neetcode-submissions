class Solution {
public:
vector<vector<int>>dp;
    int solve(int i , int j , string s , string t ){
        if(i < 0){
            return j +1 ;
        }
        if(j < 0){
            return i +1 ;
        }
        if(dp[i][j]!= -1)return dp[i][j];
        if(s[i] == t[j]) return dp[i][j]= solve(i-1 , j-1 , s, t);

        int insert = solve(i , j -1  , s, t);
        int del = solve(i -1, j  , s, t);
        int repl = solve(i -1 , j -1  , s, t);

        return dp[i][j]= 1 + min(insert , min(del , repl));
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n , vector<int>(m,-1));
        return solve(n-1 , m-1 ,word1 , word2);
    }
};
