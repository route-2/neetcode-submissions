class Solution {
public:
   
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
       int rob1 = nums[0], rob2 = max(nums[0],nums[1]);
       for(int i = 2;i<nums.size();i++){
            int temp = max(rob2,nums[i]+rob1);
            rob1 = rob2;
            rob2 = temp;
       }
       return rob2;
        
       
    }
    
};
