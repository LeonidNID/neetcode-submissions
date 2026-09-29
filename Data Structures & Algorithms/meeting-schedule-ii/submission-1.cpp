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
        if(intervals.empty()) return 0;
        
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)
        {return a.start < b.start;});
        
        int firstStart = intervals[0].start;
        int lastEndPossible = intervals[intervals.size() - 1].end + 100000;
        // vector: at time idx: +1, -1
        vector<int> v(lastEndPossible);
        for(const auto& interval : intervals) {
            v[interval.start]++;
            v[interval.end]--;
        }

        // loop:
        int running = 0;
        int maxOverlap = 0;
        for(int i = firstStart; i < lastEndPossible; i++) {
            running += v[i];
            maxOverlap = max(maxOverlap, running);
        }

        return maxOverlap; // == min meeting rooms required to accomodate all
    } 
};

/*
Seems like max overlap.
if we have at some point n conflicting meetings we need n rooms => min rooms = max overlap

*/