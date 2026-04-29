class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : nums) {
            // Only check for the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count the length of the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Update the longest streak
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
