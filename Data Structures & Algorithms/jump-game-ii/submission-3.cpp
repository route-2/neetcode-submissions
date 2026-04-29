class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = minimum number of jumps needed to reach the last index starting from index i
        // start with a big number (like infinity) because we do not know the answer yet
        vector<int> dp(n, 1000000);

        // if we are already at the last index, we need 0 jumps
        dp[n - 1] = 0;

        // fill the dp array from right to left
        // this way, when we calculate dp[i], all dp[j] for j > i are already known
        for (int i = n - 2; i >= 0; i--) {

            // from index i, the farthest we can jump is i + nums[i]
            // our loop uses j < end, so end must be one position after the last valid index
            // also make sure we do not go out of bounds
            int end = min(n, i + nums[i] + 1);

            // try every position j that we can jump to from i
            for (int j = i + 1; j < end; j++) {

                // if we jump from i to j, that costs 1 jump
                // then from j to the end, we already know the best answer dp[j]
                // so total jumps = 1 + dp[j]
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }

        // we start at index 0, so dp[0] is our final answer
        return dp[0];
    }
};