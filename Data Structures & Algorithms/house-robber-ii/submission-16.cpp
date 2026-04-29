class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1)return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int ans1 =  helper(nums,0,n-2);
        int ans2 = helper(nums,1,n-1);
        return max(ans1,ans2);

        
    }
    int helper(vector<int>& nums,int i,int j){
        //2,9,8,3
        int n = nums.size();
        int rob1 = 0;
        int rob2 = 0;

        for(int k = i;k<=j;k++){
            int temp = max(rob1+nums[k],rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;


    }
};
