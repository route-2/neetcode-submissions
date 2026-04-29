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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        

        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(intervals[i].end > intervals[j].start && intervals[i].start < intervals[j].end){
                    return false;
                }
            }
            
        }
        return true;
    }
};
