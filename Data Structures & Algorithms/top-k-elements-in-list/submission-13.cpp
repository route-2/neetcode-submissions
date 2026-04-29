class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> cmp;
        for(int i = 0;i<n;i++){
            cmp[nums[i]]++;  
        }
        vector<pair<int, int>> arr;
        for (const auto& p : cmp) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;

    }
};
