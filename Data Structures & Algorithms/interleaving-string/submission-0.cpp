class Solution {
public:

    bool solve(int i, int j, string &s1, string &s2, string &s3) {

        if(i == s1.size() && j == s2.size())
            return true;

        bool left = false;
        bool right = false;

        if(i < s1.size() && s1[i] == s3[i + j])
            left = solve(i + 1, j, s1, s2, s3);

        if(j < s2.size() && s2[j] == s3[i + j])
            right = solve(i, j + 1, s1, s2, s3);

        return left || right;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size())
            return false;

        return solve(0, 0, s1, s2, s3);
    }
};