class Solution {
public:
    vector<int> dp;

    int solve(int ind, vector<int>& stoneValue) {

        if (ind >= stoneValue.size())
            return 0;

        if (dp[ind] != INT_MIN)
            return dp[ind];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && ind + k < stoneValue.size(); k++) {

            sum += stoneValue[ind + k];

            ans = max(ans, sum - solve(ind + k + 1, stoneValue));
        }

        return dp[ind] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        dp.assign(n, INT_MIN);

        int diff = solve(0, stoneValue);

        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";

        return "Tie";
    }
};