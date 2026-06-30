class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        def backtrack(curr,start,total):
            if total == target:
                res.append(curr[:])
                return

            for i in range(start,len(nums)):
                if total + nums[i] > target:
                    continue
                
                curr.append(nums[i])
                backtrack(curr,i,total+nums[i])

                curr.pop()
                
        backtrack([],0,0)
        return res
                

        