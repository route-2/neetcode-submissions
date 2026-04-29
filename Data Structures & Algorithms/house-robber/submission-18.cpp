class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
         if (n == 0) return 0;
        if (n == 1) return nums[0];

        dp[0] = nums[0]; // if only house 0
        dp[1] = max(nums[0], nums[1]);  // best from house 0..1

        for(int i = 2;i<n;i++){
            // either skip this house -> keep dp[i-1]
            // or take this house -> nums[i] + dp[i-2]
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1]; // in the end of dp has total money robbed from houses before
        
    }
};
