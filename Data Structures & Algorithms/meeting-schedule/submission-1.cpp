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
        // sort by start-time
        sort(intervals.begin(), intervals.end(), 
            [](const Interval& a, const Interval& b){return a.start < b.start;});

        // iterate through times (max length is 500)
        int lastEnd = 0;
        for(const auto& interval : intervals) {
            if(interval.start < lastEnd) return false;
            lastEnd = interval.end;
        }

        return true; 
    }
};