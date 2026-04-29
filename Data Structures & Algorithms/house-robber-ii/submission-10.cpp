class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        return max(helper(nums1),helper(nums2));
        
    }
    int helper(vector<int>nums){
        int n = nums.size();
        int rob1 = nums[0];
        int rob2 = max(nums[0],nums[1]);

        for(int i = 2;i<n;i++){
            int temp = max(rob1 + nums[i],rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};
