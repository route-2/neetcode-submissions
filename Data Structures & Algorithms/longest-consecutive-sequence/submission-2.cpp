class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        int currStreak = 0;

        for (int num : numSet) {
            int curr = num;
            currStreak = 1;

            while(find(nums.begin(),nums.end(),curr+1)!=nums.end()){
                 curr+=1;
                 currStreak+=1;
            }

            longestStreak = max(currStreak,longestStreak);
           
           
            
        }

        return longestStreak;
    }
};
