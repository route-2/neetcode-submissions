class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
         int n = nums.size();
         vector<int> ans(2);
         unordered_map<int,int> mp;
         for(int i = 0;i<n;i++){
            int ispres = target - nums[i];
            
            if(mp.find(ispres)!=mp.end()){
               ans[1]=i;
               ans[0]=mp[ispres];
               return ans;
            }
            mp[nums[i]]=i;
         }
         return {};
    }
};
