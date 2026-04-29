class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int i = 0;
        //left part
        while(i < n && intervals[i][1]<newStart){
            res.push_back(intervals[i]);
            i++;
        }

        while( i < n && intervals[i][0]<= newEnd){
            newStart = min(intervals[i][0],newStart);
            newEnd = max(intervals[i][1],newEnd);
            i++;
        }
        res.push_back({newStart, newEnd});
        //right part
        while(i<n){
                res.push_back(intervals[i]);
                i++;
        }


          
        return res;

    }
};
