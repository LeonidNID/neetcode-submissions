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

        // vector: at time idx: +1, -1
        map<int, int> mp;
        for(const auto& interval : intervals) {
            mp[interval.start]++;
            mp[interval.end]--;
        }
        
        int conflicts = 0;
        int maxConflicts = 0;
        for(const auto& [time, c] : mp) {
            conflicts += c;
            maxConflicts = max(maxConflicts, conflicts);
        }

        return maxConflicts;
    } 
};

/*
Seems like max overlap.
if we have at some point n conflicting meetings we need n rooms => min rooms = max overlap

*/