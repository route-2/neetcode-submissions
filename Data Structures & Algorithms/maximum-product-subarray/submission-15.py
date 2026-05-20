class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        res = nums[0]
        prefix = 0
        suffix = 0

        for i in range(n):
            if prefix == 0: prefix = 1
            if suffix == 0: suffix = 1
            prefix = nums[i] * prefix
            suffix = nums[n-1-i] * suffix
            res = max(res, max(prefix,suffix))
        
        return res
        