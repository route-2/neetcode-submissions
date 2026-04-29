class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       vector<int> res;
       if(nums.size()==1) return {nums[0]};
       int n = nums.size();
       for(int i = 0;i<n;i++){
        mp[nums[i]]++;
       }  //mp = { 1 → 3, 2 → 2, 3 → 1 }
      vector<vector<int>> bucket(n+1);
      for(auto& [num,count]:mp){
        bucket[count].push_back(num);
      }

      vector<int> result;
      for(int i = n;i>=0 && result.size()<k;i--){

        for(auto & num : bucket[i]){
result.push_back(num);
        if(result.size()==k){
            return result;
        }
        }
        
          
      }
      return result;


       
        
       
    }
};
