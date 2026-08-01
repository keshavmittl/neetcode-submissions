class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string comm ="";
            int i= 0 ; 
            while(i<strs[0].size() && strs[0][i] == strs[n-1][i]){
                comm+=strs[0][i];
                i++;
            }
        return comm;
    }
};