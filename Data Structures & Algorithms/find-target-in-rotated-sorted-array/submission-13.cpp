class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int right = n-1;
        int mid = 0;

        while(low<=right){
            mid = low + (right-low)/2;
            if(target==nums[mid]){
                return mid;
            }

            if(nums[low]<=nums[mid]){
                if(target>nums[mid] || target<nums[low]){
                low = mid+1;
                }
                else {
                    right = mid -1;
                }

            } else {
                if( target<nums[mid] || target > nums[right]){
                    right = mid -1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
    };

