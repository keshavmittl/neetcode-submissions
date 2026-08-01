class Solution {
public:

    int solve(int i, int j, const string &s) {

        int cnt = 0;

        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            cnt++;
            i--;
            j++;
        }

        return cnt;
    }

    int countSubstrings(string s) {

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            // Odd length
            ans += solve(i, i, s);

            // Even length
            ans += solve(i, i + 1, s);
        }

        return ans;
    }
};