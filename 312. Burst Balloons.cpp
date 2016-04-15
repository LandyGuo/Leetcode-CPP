/*
312. Burst Balloons 
Difficulty: Hard
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
/*
思路：
动态规划:
opt(i,j)表示在（i,j）范围内(不含第i,j个气球)能得到的最大分数。
给定nums数组，前后补1后(nums[0]=1,nums[nums.size(0-1]=1)，则nums数组所能得到的最大分数就是opt(0,nums.size()-1);
动规方程:
opt(i,j)= max(opt(i,j),opt(i,m)+opt(m,j)+A[i]*A[m]*A[j]) （不含i,j）
含义：opt(i,j)的最大值为从(i,j)中挑一个气球m最后爆炸，则opt(i,m)和opt(m,j)可分为两个独立的子问题，气球m最后爆炸得分为nums[i]*nums[m]*nums[j]
关键：如果气球m不是最后一个爆炸，则opt(i,m)和opt(m,j)不独立！
注意:i,j是当前气球范围的边界(可能是nums[0],nums[nums.size()-1]，也可能是以其它气球作为边界)

由opt(i,j)的含义可知：
初始化时,opt(i,i)=0,opt(i,i+1)=0---范围内没有气球    opt(i,i+2)=nums[i]*nums[i+1]*nums[i+2](只有一个气球)

观察递推表达式：
         (i,m)  ->  (i,j)
                    
                     |
                     (m,j)
j从下往上计算，i从左往右，m从左往右
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty())
            return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>opt(nums.size(),vector<int>(nums.size(),0));
        //initialization
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(j<i+2)//opt[i][i]=0,opt[i][i+1]=0//中间无气球，只有气球爆炸才能得分
                    opt[i][j] = 0;
                else if(j==i+2)//中间只有一个气球
                    opt[i][j] = nums[i]*nums[i+1]*nums[j];
            }
        }
        //
        for(int row=nums.size()-4;row>=0;row--)//从下面的行开始求解
        {
            for(int col = row+3;col<nums.size();col++)//列序：从前往后
            {
                opt[row][col] = INT_MIN;
                for(int m=row+1;m<=col-1;m++)//选择(row,col)范围内的一个气球最后爆炸
                {
                    opt[row][col] = max(opt[row][col],opt[row][m]+opt[m][col]+nums[row]*nums[m]*nums[col]);
                }
                
            }
        }
        return opt[0][nums.size()-1];
    }
};
