/*
119. Pascal's Triangle II   
Difficulty: Easy
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
/*2nd pass
重点：从后往前更新
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<0)
            return vector<int>();
        vector<int> res(rowIndex+1,0);
        res[0] = 1;
        for(int k=1;k<=rowIndex;k++)
        {
            for(int k1=k;k1>=1;k1--)
            {
                res[k1] = res[k1]+res[k1-1];
            }
        }

        return res;
    }
};
