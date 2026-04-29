class Solution {
public:
   
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        
        int prev1 = 0; // Tracks max profit excluding the current house
        int prev2 = 0; // Tracks max profit including the current house

        for (int num : nums) {
            int temp = prev1;  // Store previous `prev1` before updating
            prev1 = max(prev1, prev2 + num);  // Decision: Rob or Skip?
            prev2 = temp;  // Move `prev2` forward to next iteration
        }
        return prev1; // Contains the max profit after considering all houses
    }
    
};
