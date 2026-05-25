from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = []
        dp.append(nums[0])
        n = len(nums)

        LIS = 1
        for i in range(n):
            # last ele in dp < nums[i]
            if dp[-1] < nums[i]:
                dp.append(nums[i])
                LIS += 1
                continue
            # bisect_left gives the exact pos where nums[i] has to be inserted > or =
            idx = bisect_left(dp,nums[i])
            dp[idx] = nums[i]
        
        return LIS
        