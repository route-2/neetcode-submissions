class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        unordered_set<int> store(nums.begin(), nums.end());

        for(int num : nums){
            int strk = 0, curr = num;
            while(store.find(curr)!=store.end()){
                strk++;
                curr++;
            }
            res = max(res,strk);
        }
        return res;

    }
};
