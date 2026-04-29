class Solution {
public:
    int findMin(vector<int> &nums) {
        //optimal
        //og array = 1,2,3,4,5,6
        //rotated = 3,4,5,6,1,2
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = 0;
        while(low<high)
        {
             mid = low + (high-low)/2;
             if(nums[mid]>nums[high]){
                low = mid+1;
             } else {
                high = mid;
             }
        }
        return nums[low];


        
       
        
    }
};
