class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);  // dp[i] = number of ways to decode from s[i] to end
        dp[n] = 1;  // base case: an empty string has 1 valid decoding

        // Loop from end of string to start (right to left)
        for (int i = n - 1; i >= 0; i--) {
            // If current digit is '0', it cannot be decoded
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                // Decode one digit → take value from dp[i+1]
                dp[i] = dp[i + 1];

                // Decode two digits if it's <= 26
                if (i + 1 < n && stoi(s.substr(i, 2)) <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        // dp[0] holds the total number of ways to decode the entire string
        return dp[0];
    }
};
