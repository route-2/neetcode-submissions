class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        int LIS = 1;

        for(int i = 1;i<n;i++){

            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
                LIS++;
                //continue just skips the rest of the current loop iteration and goes to the next i
// break would exit the loop completely, which we are not using here,
                continue;
            }

            int idx = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            dp[idx]=nums[i];
        }

        return LIS;

        
    }
};
