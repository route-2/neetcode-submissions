class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort by end times
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int removals = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            //if current start is  overlapping with prev intervals end
            if (intervals[i][0] < prevEnd) {
                removals++;
            } else 
            //update the new prev interval end to this intervals end 
            {
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
};
