class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1000000);
        dp[n - 1] = 0;
        
        for (int i = n - 2; i >= 0; i--){
             int end = min((int)nums.size(), i + nums[i] + 1);
             for (int j = i + 1; j < end; j++) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }


        }
         return dp[0];

    }
};
