class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int,int> freq;

      for(int i = 0;i<n;i++){
        freq[nums[i]]++;
      }

      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
       
       for( auto &[num,count]:freq){
        pq.push({count,num});
        if(pq.size()>k){
            pq.pop();
        }
       }
       vector<int> result;
       while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
       }
       return result;


        
       
    }
};
