class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        
        # Edge cases
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        
        
        def helper(houses):
            rob1 = houses[0]
            rob2 = max(houses[0], houses[1])
            
            for i in range(2, len(houses)):
                cur = max(rob1 + houses[i], rob2)
                rob1 = rob2
                rob2 = cur
            
            return rob2
        
        # Choice 1: Rob houses 0 to n-2 (exclude last)
        choice1 = helper(nums[0:n-1])
        
        # Choice 2: Rob houses 1 to n-1 (exclude first)
        choice2 = helper(nums[1:n])
        
        # Return maximum
        return max(choice1, choice2)