class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        res = []
        

        i = 0
        while i < len(intervals) and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1
        

        # Step 2: Merge overlapping intervals
        while i < len(intervals) and intervals[i][0] <= newInterval[1]:
            # Extend the newInterval to cover both
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
        

        res.append(newInterval)
        
        # Step 4: Add remaining intervals
        while i < len(intervals):
            res.append(intervals[i])
            i += 1
        
        return res
        