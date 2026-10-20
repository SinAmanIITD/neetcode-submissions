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
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        int n = intervals.size();
        int prevEnd = intervals[0].end;
        for(int i = 1; i<n; i++){
            int a = intervals[i].start;
            int b = intervals[i].end;
            if(prevEnd>a){
                return false;
            }
            prevEnd = intervals[i].end;
        }
        return true;
    }
};
