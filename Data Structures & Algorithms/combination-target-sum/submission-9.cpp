class Solution {
public:
     vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<int> curr ;
        int start = 0;
        int sum = 0;
         backtrack(nums,target,curr,start,sum);
         return res;
    }

   void backtrack(vector<int>& nums, int target, vector<int>& cur, int start,int sum){
      if(sum==target){
        res.push_back(cur);
        return;
      }

       for(int i = start;i<nums.size();i++){
         if(sum+nums[i]>target){
            //skips the index moves to next
            continue;
        }
        cur.push_back(nums[i]);//choose

        backtrack(nums,target,cur,i,sum+nums[i]);//explore
        cur.pop_back();//unchoose
       }

      
    }
};
