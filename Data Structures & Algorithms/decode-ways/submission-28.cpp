class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int dp1 = 1; // dp[i+1]
        int dp2 = 0; // dp[i+2]
        int cur = 0; // dp[i]

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                cur = 0;
            } else {
                cur = dp1;

                if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                    cur += dp2;
                }
            }

            dp2 = dp1;
            dp1 = cur;
        }

        return dp1;
    }
};