class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int longS = 1;
        int curr = 1;

//[2,3,4,4,5,10,20]
        for(int i = 1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    curr++;
                } else {
                    longS = max(curr,longS);
                    curr = 1;
                }
            }
            

        }
        return max(longS,curr);

      
    }
};
