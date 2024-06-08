class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length();
        int n = s.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // Initialize dp array
        dp[m][n] = true; // Empty pattern matches empty string

        // Fill the dp array
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (i == m && j == n) {
                    dp[i][j] = true;
                } else if (i == m) {
                    dp[i][j] = false;
                } else if (j == n) {
                    dp[i][j] = (p[i] == '*') && dp[i+1][j];
                } else {
                    if (p[i] == '*') {
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    } else if (p[i] == '?') {
                        dp[i][j] = dp[i+1][j+1];
                    } else {
                        dp[i][j] = (p[i] == s[j]) && dp[i+1][j+1];
                    }
                }
            }
        }

        return dp[0][0];
    }
};