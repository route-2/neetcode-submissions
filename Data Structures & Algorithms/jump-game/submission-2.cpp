class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int goal = n-1;
        int steps = 0;

        for(int i = n-2;i>=0;i--){
            //starts from end move the goal closer to start
            //if index + number at that points is steps
            //if it is greater or = it means we know we can reach from here
            //so we reduce goal
            if(i+nums[i]>=goal){
                goal = i;
            }
              
        }
        return goal==0;
       

        
    }
};
