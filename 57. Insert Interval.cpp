/*
57. Insert Interval   
Difficulty: Hard
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 /*2nd pass
 思路：
 1.因为intervals已经按start有序，因此将newIntervals之前的都按常规方法进行合并
 2.合并newInterval
 3.从刚刚合并被newInterval中断的地方开始，继续合并
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        if(intervals.empty())
        {
            ret.push_back(newInterval);
            return ret;
        }
        int i=0;
        //因为intervals已经按start有序，因此将newIntervals之前的都按常规方法进行合并
        while(i<intervals.size()&&intervals[i].start<=newInterval.start)
        {
            if(ret.empty()||(!ret.empty()&&intervals[i].start>ret.back().end))
                ret.push_back(intervals[i]);
            else
            {
                Interval lastInterval = ret.back();
                ret.pop_back();
                Interval merge_interval =Interval(min(intervals[i].start,lastInterval.start),max(intervals[i].end,lastInterval.end));
                ret.push_back(merge_interval);
            }
            i++;
        }
        //合并newInterval
        if(ret.empty()||(!ret.empty()&&newInterval.start>ret.back().end))
            ret.push_back(newInterval);
        else
        {
                Interval lastInterval = ret.back();
                ret.pop_back();
                Interval merge_interval =Interval(min(newInterval.start,lastInterval.start),max(newInterval.end,lastInterval.end));
                ret.push_back(merge_interval);
        }
        //从刚刚合并被newInterval中断的地方开始，继续合并
        while(i<intervals.size())
        {
            if(ret.empty()||(!ret.empty()&&intervals[i].start>ret.back().end))
                ret.push_back(intervals[i]);
            else
            {
                Interval lastInterval = ret.back();
                ret.pop_back();
                Interval merge_interval =Interval(min(intervals[i].start,lastInterval.start),max(intervals[i].end,lastInterval.end));
                ret.push_back(merge_interval);
            }
            i++;
        }
        return ret;
    }
};
