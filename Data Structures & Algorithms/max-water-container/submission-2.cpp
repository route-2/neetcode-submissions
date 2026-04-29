class Solution {
public:
    int maxArea(vector<int>& height) {
       int n = height.size();
       if(n==1 || n ==0) return 0;
       int left = 0;
       int leftMax = INT_MAX;
       int right = n-1;
       int rightMax = INT_MAX;
       int water = 0;

       while(left<right){
        leftMax = height[left];
        rightMax = height[right];

        water = max(water, (right - left) * min(leftMax, rightMax));
        if(leftMax<rightMax){
           left++;
        }
        else {
             right--;
        }
       
       
        
       }
       return water;

       
       
        
    }
};
