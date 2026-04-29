class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> freq;

        for(int i = 0;i<n;i++){
            freq[nums[i]]++;
        }
        // 1 -> 1
        // 2->2
        //3 -> 3

         
        
        priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minH;
        
         for (auto& [num, count] : freq){
            minH.push({count,num});
            //this ensures the least freq ones gets popped
            if(minH.size()>k){
                minH.pop();
            }
         }


        // Sort frequencies in descending order based on occurrence count
        vector<int> result;
        while (!minH.empty()) {
            result.push_back(minH.top().second);
            minH.pop();
        }
        return result;
    }
};
