class Solution {
public:
     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // sort by start
        int maxKept = dfs(0, -1, intervals);
        return intervals.size() - maxKept;
    }

private:
    int dfs(int i, int prev, vector<vector<int>>& intervals) {
        if (i == intervals.size()) return 0;

        // Option 1: skip current interval
        int skip = dfs(i + 1, prev, intervals);

        // Option 2: take current interval if no overlap
        int take = 0;
        if (prev == -1 || intervals[i][0] >= intervals[prev][1]) {
            take = 1 + dfs(i + 1, i, intervals);
        }

        return max(skip, take);
    }
    
};
