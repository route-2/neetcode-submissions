class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
       int longS = 1;
       int n = nums.size();
       if(n==0) return 0;
       sort(nums.begin(),nums.end());
       int curr = 1;

       //0,1,1,2,3,4,5,6

       for(int i = 1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            if(nums[i]==nums[i-1]+1){
               curr++;
            }
             else {
                longS = max(longS,curr);
                curr = 1;
            }
        }
       

          
       }
       return max(longS,curr);


      
    }
};
