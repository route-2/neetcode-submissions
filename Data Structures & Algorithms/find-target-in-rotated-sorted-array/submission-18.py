class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = l + (r - l) // 2

            if target == nums[mid]:
                return mid
            
            if nums[l] <= nums[mid]:  # LEFT HALF IS SORTED
                if target > nums[mid] or target < nums[l]:
                    # Target is outside the sorted left half
                    l = mid + 1  # Search right
                else:
                    # Target is inside the sorted left half
                    r = mid - 1  # Search left
            else:  # RIGHT HALF IS SORTED
                if target < nums[mid] or target > nums[r]:
                    # Target is outside the sorted right half
                    r = mid - 1  # Search left
                else:
                    # Target is inside the sorted right half
                    l = mid + 1  # Search right
        
        return -1