class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        return dfs(nums, 0, sum / 2);
    }

    bool dfs(vector<int>& nums, int i, int target) {
        if (i == nums.size()) {
            return target == 0;
        }
        if (target < 0) {
            return false;
        }

        return dfs(nums, i + 1, target) ||
               dfs(nums, i + 1, target - nums[i]);
    }
};