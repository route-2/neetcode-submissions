/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

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
        int s = 0, e = 0;

         while (s < n) {
          if(starts[s]<ends[e]){
            rooms++;
            maxRooms = max(rooms,maxRooms);
            s++;
          } else {
            rooms--;
            e++;
          }
         }
         return maxRooms;
        
    }
};
