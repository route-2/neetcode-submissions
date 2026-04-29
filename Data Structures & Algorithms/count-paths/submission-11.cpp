class Solution {
public:
    int uniquePaths(int m, int n) {
vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //treat dp[j] as top 
                //dp[j-1] as left
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
