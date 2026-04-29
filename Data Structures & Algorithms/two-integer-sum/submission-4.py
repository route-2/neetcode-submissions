class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n == 0 :
            return []
        ans = [0] * 2
        mp = {}

        for i,num in enumerate(nums):
            ispres = target - num

            if ispres in mp:
                ans[1] = i
                ans[0] = mp[ispres]
                return ans
            mp[num] = i
        return []