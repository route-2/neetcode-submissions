class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return dfs(0, -1, nums);
    }

    int dfs(int i, int prev, vector<int>& nums) {
        if (i == nums.size()) return 0;

        int notTake = dfs(i + 1, prev, nums);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + dfs(i + 1, i, nums);
        }

        return max(take, notTake);
    }
};