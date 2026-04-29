class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Put all numbers into an unordered_set
        //   - This removes duplicates
        //   - Allows O(1) lookup when checking if a number exists
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        // Step 2: Iterate over the original numbers
        for (int num : nums) {
            // Only start counting if this number is the BEGINNING of a sequence
            // i.e. num - 1 is NOT in the set
            if (st.find(num - 1) == st.end()) {
                int len = 1; // current streak length

                // Keep extending the streak as long as (num + len) exists
                while (st.find(num + len) != st.end()) {
                    len++;
                }

                // Update the maximum streak found so far
                longest = max(longest, len);
            }
        }

        return longest;
    }
};
