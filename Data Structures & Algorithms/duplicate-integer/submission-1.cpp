class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i =0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                   mp[nums[i]]++;
            }
            mp[nums[i]]++; 

        }

        int ans = false;

        for(auto &i : mp){
            if(i.second >=2){
                 ans = true;
            }
        }
        return ans;



    }
};
