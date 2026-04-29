class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

       if(nums.empty()) return 0;
       int longestStreak = 1;
       int currStreak = 1;
       sort(nums.begin(),nums.end());

        for (int i = 1; i < nums.size(); i++) {  // Iterate through each element
          
           

            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                     currStreak+=1;
                }
                else {
                    longestStreak = max(longestStreak, currStreak);
                    currStreak = 1;
                }
            }
           
            

            
        }

       return max(longestStreak, currStreak); 
    }
};
