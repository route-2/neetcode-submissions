class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
         int ele = 0;

        for(int i = n-1;i>=n-k;i--){
            ele = nums[i];
            
             
        }
        return ele;
        
    }
};