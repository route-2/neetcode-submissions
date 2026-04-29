class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> curr ;
         backtrack(nums,target,curr,0);
         return res;
    }

   void backtrack(vector<int>& nums, int target, vector<int>& cur, int i) {
        
        int n =nums.size();
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }
         cur.push_back(nums[i]);  
          backtrack(nums, target - nums[i], cur, i);
        cur.pop_back();
        backtrack(nums, target, cur, i + 1);


        
   }
};
