class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int water = 0;

        while(l<r){
            int area = min(heights[l],heights[r]) * (r-l);

            water = max(water,area);

            if(heights[l]<=heights[r]){
                l++;
            } else {
                r--;
            }

        }
        return water;
        
    }
};
