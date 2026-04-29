class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> freq;
  //nums = [1,1,1,2,2,3], k = 2
        for(int i = 0;i<n;i++){
            freq[nums[i]]++;
        }
        //freq = { 1 → 3, 2 → 2, 3 → 1 }
        vector<vector<int>> bucket(n+1);
       // bucket[3] = [1]
       //bucket[2] = [2]
       //bucket[1] = [3]
        for(auto& [num,count]:freq){
            bucket[count].push_back(num);
        }

        vector<int> result;
        for(int i = n;i>=0 && result.size()<k;i--){
              for(auto& num:bucket[i]){
                result.push_back(num);
                 if (result.size() == k) return result; //stop once it reaches k size
              }
        }
        return result;

         
        
       
    }
};
