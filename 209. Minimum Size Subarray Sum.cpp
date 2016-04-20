/*
209. Minimum Size Subarray Sum 
Difficulty: Medium
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/
/*2nd pass
维持一个和始终能>=s的队列
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        deque<int> que;
        int curSum = 0,res =INT_MAX;
        for(auto num:nums)
        {
            que.push_back(num);
            curSum+=num;
            if(curSum>=s)//每当超出s就更新res
            {
                int curSize  = que.size();
                res = min(res,curSize);
                while(curSum-que.front()>=s)//并看能否通过弹出前面的值继续更新res
                {
                    curSum-=que.front();
                    que.pop_front();
                    int quesize = que.size();
                    res = min(quesize,res);
                }
            }
        }
        return res==INT_MAX?0:res;
    }
};
