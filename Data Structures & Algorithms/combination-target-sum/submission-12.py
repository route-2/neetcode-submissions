class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        
        def backtrack(curr, start, sum_val):
            if sum_val == target:
                res.append(curr[:])
                return
            
            for i in range(start, len(nums)):
                if sum_val + nums[i] > target:
                    continue
                
                curr.append(nums[i])
                backtrack(curr, i, sum_val + nums[i])
                curr.pop()
        
        backtrack([], 0, 0)
        return res


