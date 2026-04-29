class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        If nums[i] > dp.back():
→ Extend the current longest subsequence

If nums[i] ≤ dp.back():
→ Replace the **first number in dp ≥ nums[i]** using lower_bound`


        */
        int n = nums.size();
        if(n==0) return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        int LIS = 1;

        for(int i = 1;i<n;i++){

            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
                LIS++;
                //continue just skips the rest of the current loop iteration and goes to the next i
// break would exit the loop completely, which we are not using here,
                continue;
            }
/*
You're finding the iterator to the first element in dp ≥ nums[i],
Then you subtract dp.begin() to get the index.
*/

/*
Under the hood:
It's a binary search — log₂(n) comparisons

Time complexity: O(log n)

Works only on sorted ranges


*/
            int idx = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            dp[idx]=nums[i];
        }

        return LIS;

        
    }
};

/*
i | nums[i] | Action | dp (after step) | Explanation
0 | 10 | Push (first element) | [10] | new start
1 | 9 | 9 < 10 → replace dp[0] = 9 | [9] | shrink tail
2 | 2 | 2 < 9 → replace dp[0] = 2 | [2] | even smaller tail
3 | 5 | 5 > 2 → push | [2, 5] | extend LIS
4 | 3 | 3 < 5 → replace dp[1] = 3 | [2, 3] | smaller tail for len=2
5 | 7 | 7 > 3 → push | [2, 3, 7] | extend
6 | 101 | 101 > 7 → push | [2, 3, 7, 101] | extend
7 | 18 | 18 < 101 → replace dp[3] = 18 | [2, 3, 7, 18] | better tail for len=4
*/
