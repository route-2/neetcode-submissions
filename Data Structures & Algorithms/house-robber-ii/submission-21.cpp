class Solution {
public:
    vector<int> memo;
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        memo.assign(n, -1);
        int case1 = dfs(0, n - 2, nums);

        memo.assign(n, -1);
        int case2 = dfs(1, n - 1, nums);

        return max(case1, case2);
    }

    int dfs(int i, int j, vector<int>& nums) {
        if(i > j) return 0;
        if(memo[i] != -1) return memo[i];

        memo[i] = max(nums[i] + dfs(i + 2, j, nums),
                      dfs(i + 1, j, nums));
        return memo[i];
    }
};