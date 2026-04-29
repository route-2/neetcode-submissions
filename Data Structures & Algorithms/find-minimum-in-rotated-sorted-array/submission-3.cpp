class Solution {
public:
    int findMin(vector<int> &nums) {
        int minValue = nums[0]; // Assume first element is the smallest
        for (int i = 1; i < nums.size(); i++) {
            minValue = min(minValue, nums[i]); // Keep track of the minimum element
        }
        return minValue;


        
    }
};
