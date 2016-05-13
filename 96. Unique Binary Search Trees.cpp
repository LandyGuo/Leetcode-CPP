/*
96. Unique Binary Search Trees   
Difficulty: Medium
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
//2nd pass
/*
思路：
opt[0] = 1
opt[1] = 1 一个节点只有1种
opt[2] = opt[1](以2个节点的第一个节点作为根节点)+opt[1](以2个节点的第2个节点作为根节点)
opt[3] = opt[2](以3个节点的第一个节点作为根节点，剩下的2个节点都在右分支)+
        opt[1]*opt[1](以3个节点的第2个节点作为根节点，剩下的2个节点一个在左分支，一个在右分支)
        opt[2](以3个节点的第3个节点作为根节点，剩下的2个节点都在左分支)
opt[4] = opt[3]+opt[1]*opt[2]+opt[2]*opt[1]+opt[3]
_______为统一起见，如果定义opt[0]=1,则所有形式可以统一为:
opt[4] = opt[0]*opt[3]+opt[1]*opt[2]+opt[2]*opt[1]+opt[3]*opt[0]
从而推得动态规划方程
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int>opt(n+1,0);
        opt[0]=1,opt[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
                opt[i]+=opt[j]*opt[i-1-j];
        }
        return opt[n];
    }
};
