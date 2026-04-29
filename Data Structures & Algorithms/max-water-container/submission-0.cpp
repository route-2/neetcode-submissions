class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        if(n==1 || n ==0) return 0;
        int water = 0;

        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
              water= max(water,(j-i)*min(heights[i],heights[j]));

               

            }
        }
        return water;
        
    }
};
