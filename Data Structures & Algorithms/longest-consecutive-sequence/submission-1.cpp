class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        int currStreak = 0;

        for (int num : numSet) {
           
            if(numSet.find(num-1)==numSet.end()){
                   int curr = num;
                    currStreak = 1;

                   while(numSet.find(curr+1)!=numSet.end()){
                        curr+= 1;
                        currStreak +=1;
                   }
               longestStreak = max(currStreak,longestStreak);

            }
            
            
        }

        return longestStreak;
    }
};
