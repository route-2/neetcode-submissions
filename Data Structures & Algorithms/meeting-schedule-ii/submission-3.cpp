class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        vector<int> starts(n), ends(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;
        int maxRooms = 0;
        int s = 0;
        int e = 0;

        while (s < n) {
            // if the next meeting starts before the earliest meeting ends,
            // we need one more room
            if (starts[s] < ends[e]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                s++;
            } 
            // otherwise one meeting has already ended,
            // so free one room and move the end pointer
            else {
                rooms--;
                e++;
            }
        }

        return maxRooms;
    }
};
