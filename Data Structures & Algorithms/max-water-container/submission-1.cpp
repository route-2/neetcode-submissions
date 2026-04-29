class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n==1 || n ==0) return 0;
        int water = 0;

        int left = 0;
       

        int right = n-1;
       

        while(left<right){
             int leftMax = height[left];
             int rightMax = height[right];
             water=max(water,(right-left)*min(leftMax,rightMax));
             if(leftMax<rightMax){
            left++;
        }
        else {
            right --;
        }
           
           

        }

        
        return water;
        
    }
};
