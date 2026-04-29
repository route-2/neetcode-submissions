class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> hs;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int h = n - 1;

            while (l < h) {
                int sum = nums[i] + nums[l] + nums[h];
                if (sum == 0) {
                    hs.insert({nums[i], nums[l], nums[h]});
                    l++;
                    h--;
                } else if (sum < 0) {
                    l++;
                } else {
                    h--;
                }
            }
        }

        // Convert set to vector
        return vector<vector<int>>(hs.begin(), hs.end());
    }
};
