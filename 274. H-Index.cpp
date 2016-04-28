/*
274. H-Index  
Difficulty: Medium
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/
//2nd pass
/*
思路：
H-index的范围在[0,length],因此可以申请一个数组，对每个值进行统计(大于length的算在length上)出现次数；
数组下标为H-index,值为>=H-index的有多少篇（从后进行累积），返回引用次数>=i的i即为H-index
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //
        vector<int> opt(citations.size()+1,0);
        for(int v:citations)
        {
            if(v>=citations.size())
                opt[citations.size()]+=1;
            else
                opt[v]+=1;//类似于计数排序，统计出现次数的同时，将其按照value大小直接对应到下标,这样大于某个值的有多少次直接从后往前累加即可
        }
        for(int i = citations.size()-1;i>=0;i--)//从后往前累加，得到每个Index出现的次数
            opt[i]+=opt[i+1];
        int res = 0;
        for(int i = citations.size();i>=0;i--)
        {
            if(i<=opt[i])//引用次数>=i的有opt[i]篇，只有当opt[i]>=i时才是H-index
            {
                res = i;
                break;
            }
        }
        return res;
        
    }
};
