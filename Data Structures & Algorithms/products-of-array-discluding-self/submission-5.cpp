class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);

        //prefix
        int n = nums.size();
        for(int i =1;i<n;i++){
            res[i] = nums[i-1] * res[i-1];
        }

        //postfix
        int postfix = 1;
        for(int i = n-1;i>=0;i--){
            res[i]=res[i] * postfix;
            postfix = postfix * nums[i];
        }

        return res;

    }
};
