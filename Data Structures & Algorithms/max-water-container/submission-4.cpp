class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int water = 0;

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                water = max(water,min(heights[i],heights[j])*(j-i));

            }
        }
        return water;

        
    }
};
