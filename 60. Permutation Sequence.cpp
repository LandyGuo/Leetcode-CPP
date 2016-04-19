/*
60. Permutation Sequence  
Difficulty: Medium
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factor(n,1);
        for(int i=1;i<n;i++)
            factor[i] = factor[i-1]*i;//0!-(n-1)!
        vector<int>availNums;
        for(int i = 1;i<=n;i++)
            availNums.push_back(i);
        string res;
        while(!availNums.empty())
        {
            int ways = factor[availNums.size()-1];//每组有(n-1)!
            //cal k 
            int rank = int(ceil(double(k)/ways));//根据K计算当前所在的组
            char tmp[2];
            sprintf(tmp,"%d",availNums[rank-1]);//当前位是当前可用数由小到大排列的的第k-1个
            res += string(tmp);
            availNums.erase(availNums.begin()+rank-1);//将已经用过的数设置为不可用
            //update k
            k = k - (rank-1)*ways;//更新k
        }
        return res;
    }
};
