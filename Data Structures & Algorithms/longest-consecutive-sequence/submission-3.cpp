class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int longestStreak = 0;

        for (int i = 0; i < nums.size(); i++) {  // Iterate through each element
            int curr = nums[i];
            int currStreak = 1;

            for (int j = 0; j < nums.size(); j++) {  // Check if `curr + 1` exists
                if (nums[j] == curr + 1) {  
                    curr += 1;
                    currStreak += 1;
                    j = -1;  // Reset j to start from beginning (to find next `curr + 1`)
                }
            }

            longestStreak = max(longestStreak, currStreak);
        }

        return longestStreak;
    }
};
