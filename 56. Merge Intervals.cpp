/*
56. Merge Intervals   
Difficulty: Hard
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
 //2nd pass
 /*
 初始思路：
1）两个区间的合并很容易，如果两个区间有交集，那么区间[a,b]和区间[c,d]合并的结果是[min(a,c),max(b,d)]
2）用一个集合，集合保持这样的性质：集合中的所有区间都不能再合并；每当来一个新的区间与集合中所有的区间比较，看能否进行合并，最终这个集合就是合并之后所有区间
存在的问题：
i)新来一个区间需要和当前区间里面所有的区间进行比较看能否合并
ii)集合中可以和新来的区间进行合并的区间可能有多个，如何选择和哪个合并？
iii)与新来的区间进行合并后，很可能导致集合中原本不能合并的区间现在可以合并了，即可能导致一连串的合并
非常麻烦！！！！
需要对原来的序列根据start或者end进行排序！
1）如果根据start递增进行排序，那么新来一个区间如果能和上一个区间合并则进行合并，保证了不会出现:
   1___________1
        2________2
     3______________3 这种情况出现！因此每个实际上只用考虑与排序后之前的一个区间比较能不能合并即可，
     合并后保证ret集合中，每个区间start>上一个区间的end,新来的区间的start>上一个区间的start,因此新来的区间最多只能与上一个区间进行
     合并！！！
2)如果根据end递增进行排序，会出现上图中需要循环与上个区间比较能不能合并的情形
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.empty()) return ret;
        sort(intervals.begin(),intervals.end(),[](Interval const & a,Interval const&b){return a.start<b.start;});
        ret.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            Interval cur = intervals[i];
            if(cur.start>ret.back().end)
                ret.push_back(cur);
            //可以合并
            else
            {
                cur = Interval(min(cur.start,ret.back().start),max(cur.end,ret.back().end));
                ret.pop_back();
                ret.push_back(cur);
            }
        }
        return ret;
    }
};
