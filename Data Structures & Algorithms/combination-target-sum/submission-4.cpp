class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr ;
        int start = 0;
        int total = 0;
         backtrack(nums,target,curr,start,total);
         return res;
    }

   void backtrack(vector<int>& nums, int target, vector<int>& cur, int start,int total) {
        
      if(total==target){
        res.push_back(cur);
        return;
      }
      for(int i = start;i<nums.size();i++){
        if(total+nums[i]>target){
            continue;
        }
        cur.push_back(nums[i]);
        backtrack(nums,target,cur,i,total+nums[i]);
        cur.pop_back();
      }

        
   }
};
