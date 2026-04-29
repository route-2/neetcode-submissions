class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curSum = INT_MIN;
        int maxi = nums[0];

        for(int i = 0;i<n;i++){
            if(curSum<0){
                curSum = 0;
            }
            curSum+=nums[i];
            maxi=max(curSum,maxi);
            
        }
        return maxi;

    }
};
