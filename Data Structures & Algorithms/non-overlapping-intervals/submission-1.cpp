class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort intervals by their **end time**
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];  
        });

        int count = 0; // Number of intervals to remove
        int lastEnd = intervals[0][1]; // Track the last interval's end time

        // Step 2: Traverse the sorted intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEnd) {
                // Step 3: Overlapping interval → remove it
                count++;
            } else {
                // Step 4: No overlap → update lastEnd
                lastEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};
