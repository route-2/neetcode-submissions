class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int n = intervals.size();
        vector<vector<int>> res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int i = 0;

        // ✅ Step 1: Add all intervals that come BEFORE the newInterval
        while (i < n && intervals[i][1] < newStart) {
            res.push_back(intervals[i]);
            i++;
        }

        // ✅ Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newEnd) {  
            newStart = min(intervals[i][0], newStart);
            newEnd = max(intervals[i][1], newEnd);
            i++;
        }
        res.push_back({newStart, newEnd});  // Push the fully merged interval

        // ✅ Step 3: Add all intervals that come AFTER the merged interval
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;

    }
};
