class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int m = 0;

        while(l<=h){
             m = l + (h-l)/2;
             if(nums[m]==target)return m;
             if(nums[m]>target){
                h = m-1;
             }else {
                l = m+1;
             }
        }
        return -1;
        
    }
};
