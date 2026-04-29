class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        int prefix = 0, suffix = 0;

        for (int i = 0; i < n; i++) {
            if(prefix==0)prefix = 1;
            if(suffix==0)suffix = 1;
            prefix = nums[i] * prefix;
            suffix = nums[n - 1 - i] *  suffix;
            res = max(res, max(prefix, suffix));
        }
        return res;
    }
};