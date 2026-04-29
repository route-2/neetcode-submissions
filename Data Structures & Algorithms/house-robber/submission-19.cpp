class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int rob1 = 0;
        int rob2 = 0;
        int temp = 0;

        for(int i = 0;i<n;i++){
            //[rob1,rob2,n,n+1,n+2......]
            /*
            rob1 -> best we could do up to house i-2
            rob2 -> best we could do up to house i-1

            now for house i, we do:

            take it -> rob1 + nums[i]
            or skip it -> rob2

            */
            temp = max(rob1 + nums[i],rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;



        
        
    }
};