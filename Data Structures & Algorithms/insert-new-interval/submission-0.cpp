class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];



        for(int i = 0;i<n;i++){
            //first interval starts after my newEnd
            if(intervals[i][0]>newEnd){
                res.push_back(newInterval); //push this first
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            }
            //end of intervals i is less than my new start
            else if(intervals[i][1] < newStart){
               res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                 newInterval[1] = max(newInterval[1], intervals[i][1]);
            }



        }
          res.push_back(newInterval);
        return res;

    }
};
