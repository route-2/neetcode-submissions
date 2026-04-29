class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curSum = 0;
        int maxSub = nums[0];
        for (int num : nums) {
            if(curSum<0){
                curSum = 0;
            }
            curSum+=num;
            maxSub = max(maxSub,curSum);
                 
        }
        return maxSub;

    }
};
