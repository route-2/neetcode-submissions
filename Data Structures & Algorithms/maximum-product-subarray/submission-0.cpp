class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];

        for(int i = 0;i<nums.size();i++){
            int curr = 1;
            for (int j = i ; j < nums.size(); j++){
                 curr *= nums[j];
                 res = max(res, curr);
            }
        }
        return res;
        
    }
};
