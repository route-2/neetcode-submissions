class Solution {
public:
    int numDecodings(string s) {
        // idea:
        // dp[i] = number of ways to decode substring starting at i
        //
        // we don't store the whole dp array.
        // we only keep:
        // dp1 = dp[i+1] (one step ahead)
        // dp2 = dp[i+2] (two steps ahead)
        // dp  = dp[i]   (current)

        int dp = 0, dp2 = 0;

        // base case: dp[n] = 1 (empty string has 1 valid way)
        int dp1 = 1;

        // walk from right to left, building dp[i]
        for (int i = s.size() - 1; i >= 0; i--) {

            // if current char is '0', you can't decode starting here
            if (s[i] == '0') {
                dp = 0;
            } else {
                // take 1 digit: contributes dp[i+1]
                // (that's what dp1 is holding right now)
                dp = dp1;

                // take 2 digits if valid ("10".."26"):
                // if s[i]=='1' -> always valid with next digit
                // if s[i]=='2' -> valid only if next digit <= '6' (i.e., < '7')
                if (i + 1 < s.size() && (s[i] == '1' ||
                    (s[i] == '2' && s[i + 1] < '7'))) {

                    // add dp[i+2] ways (that's what dp2 is holding)
                    dp += dp2;
                }
            }

            // shift window for next loop (moving left):
            // after computing dp[i], we want:
            // dp2 to become old dp[i+1]
            // dp1 to become dp[i]
            dp2 = dp1;
            dp1 = dp;

            // clear dp (not required, but keeps it obvious "dp is current only")
            dp = 0;
        }

        // at the end dp1 holds dp[0] = ways to decode whole string
        return dp1;
    }
};