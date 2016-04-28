/*
275. H-Index II 
Difficulty: Medium
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
*/
//2nd pass
/*
思路：仔细思考H-index的含义：值  >=  （大于等于该值的次数）     的（值）
尽量找相等的
如果一个数组从小到大排列：
0 1 2 3 4
那么：值  大 ，范围往左移，（大于等于该值的次数） 才会变大
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        int l=0,r=length-1,mid=l+(r-l)/2;
        while(l<=r)
        {
            if(citations[mid]==length-mid)
                return length-mid;
            else if(citations[mid]>length-mid)//mid值大，往左移减小mid值，同时增大引用次数计数
                r = mid-1;
            else
                l = mid+1;
            mid=l+(r-l)/2;
        }
        return length-l;
    }
};
