class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort the array
        vector<pair<int, int>> freq; // (num, frequency)
        vector<int> ans;
        
        int count = 1; // Start with 1 since a single element appears at least once
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++; // Increase count for the same element
            } else {
                freq.push_back({nums[i - 1], count}); // Store the previous element frequency
                count = 1; // Reset count for the new number
            }
        }
        freq.push_back({nums[n - 1], count}); // Store the last element frequency

        // Sort frequencies in descending order based on occurrence count
        sort(freq.begin(), freq.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });

        // Pick top K frequent elements
        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};
