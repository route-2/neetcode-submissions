class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> freqMap;  // Store frequency of each number
        vector<pair<int, int>> freqVec;   // Store (num, frequency) pairs
        vector<int> result;               // Store final top k elements
        
        // Step 1: Count frequencies
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Move (num, frequency) pairs to a vector
        for (auto it : freqMap) {
            freqVec.push_back({it.first, it.second});
        }

        // Step 3: Sort vector in descending order based on frequency
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });

        // Step 4: Extract top K frequent elements
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};
