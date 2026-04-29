class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        // dp1 = ways to decode from i+1 onward (like dp[i+1])
        // dp2 = ways to decode from i+2 onward (like dp[i+2])
        int dp1 = 1;  // base case: empty string has 1 way to decode
        int dp2 = 0;  // initially assume dp[i+2] = 0
        int dp = 0;   // temporary variable for dp[i]

        // Start looping from the last character toward the first (right to left)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // '0' can't be decoded by itself
                dp = 0;
            } else {
                // At least 1-digit decode is always valid (if not '0')
                dp = dp1;

                // If two-digit number is valid (10 to 26), add dp2
                if (i + 1 < n && stoi(s.substr(i, 2)) <= 26) {
                    dp += dp2;
                }
            }

            // Shift the window:
            // Current dp1 becomes next dp2
            // Current dp becomes new dp1
            dp2 = dp1;
            dp1 = dp;

            // Reset dp for next iteration
            dp = 0;
        }

        // Final answer: ways to decode the full string starting at index 0
        return dp1;
    }
};
