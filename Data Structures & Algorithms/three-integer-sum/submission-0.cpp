class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> final;

        for(int i = 0;i<n;i++){
            vector<int>ans(3);
            for(int j=i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if( nums[i] + nums[j] + nums[k] == 0){
                         vector<int> triplet = {nums[i], nums[j], nums[k]};
                         sort(triplet.begin(), triplet.end());  // Sort to avoid duplicates
                        if(find(final.begin(), final.end(), triplet) == final.end()) {
                            final.push_back(triplet);
                        }
                    }
                }
            }
            
        }
        return final;
        
    }
};
