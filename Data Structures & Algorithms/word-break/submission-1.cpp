class Solution {
public:
    vector<int>dp; 
    bool dfs(int ind ,string s , vector<string>&words){
        if(ind == s.size())return true; 
        if(dp[ind] != -1 )return dp[ind];
        for(string& w : words){
            if(ind + w.size() <= s.size() && s.substr(ind , w.size()) == w){
                if(dfs(ind+w.size() , s, words)) return dp[ind] = true;
            }
        }
        return dp[ind] =false; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size() ,-1);
        return dfs(0 ,s, wordDict);
    }
};
