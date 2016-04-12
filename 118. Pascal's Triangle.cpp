/**
118. Pascal's Triangle
Difficulty: Easy
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
**/
/*
pass2:
    思路:上一层两边加0，然后相邻两个相加，构成下一层
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)
            return res;
        res.push_back(vector<int>(1,1));//注意：这句相当于初始化条件，不要放在下面numRows==1这个条件里面
        if(numRows==1)
            return res;
        for(int i=2;i<=numRows;i++)
        {
            vector<int> curRow;
            deque<int> dequeue(res.back().begin(),res.back().end());//取上一层
            dequeue.push_back(0);
            dequeue.push_front(0);//在上一层前后加0
            for(int j=1;j<dequeue.size();j++)//上一层相邻两个相加构成下一层
                curRow.push_back(dequeue[j]+dequeue[j-1]);
            res.push_back(curRow);
        }
        return res;
    }
};
