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
                LIS++;
                dp.push_back(nums[i]);
                continue;
            }
            //lower bound returns an iterator to that num >= other values
            //subtracting gives us the correct index where it should be placed
             //lower bound finds a place in dp where nums[i]>=existing elements in dp
             //subtracting gives the index where nums[i] must be placed
            int idx = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
            dp[idx] = nums[i]; 
           
            
        }
        return LIS;

        
    }
};
