class Solution {
public:
   
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
       int rob1 = 0, rob2 = 0;
       for(int num : nums){
            int temp = max(rob2,num+rob1);
            rob1 = rob2;
            rob2 = temp;
       }
       return rob2;
        
       
    }
    
};
