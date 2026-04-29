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
       if (intervals.empty()) return 0;

        // Step 1: Sort intervals by start time
       sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
           return a.start < b.start;
       });

       priority_queue<int, vector<int> , greater<int>> minHeap;
       

       for(auto& meeting: intervals){
         int start = meeting.start;
         int end = meeting.end;

         if(!minHeap.empty() && minHeap.top()<=start){
            minHeap.pop();
         }
         minHeap.push(end);
       }

       return minHeap.size();
        
    }
};
