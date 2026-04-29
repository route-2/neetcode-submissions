class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr ;
         backtrack(nums,target,curr,0);
         return res;
    }

   void backtrack(vector<int>& nums, int target, vector<int>& cur, int start) {
        
       if (target == 0) {
        res.push_back(cur);
        return;
    }
    if (target < 0) return;

    for (int i = start; i < nums.size(); i++) {
        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], cur, i); // reuse same i
        cur.pop_back(); // backtrack
    }

        
   }
};
