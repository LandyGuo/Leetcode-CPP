/*
42. Trapping Rain Water   
Difficulty: Hard
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 

 ^ 
3|              ■           □: water 
2|      ■ □ □ □ ■ ■ □ ■     ■: elevation map 
1|  ■ □ ■ ■ □ ■ ■ ■ ■ ■ ■
  ————————————————————————>
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
*/
/*
思路：
单纯只考虑有2根柱子height[l],height[r]的情形：
两根柱子之间能容纳的水由water_level = min(height[l],height[r])来决定，但是由于中间还会有很多石柱子挡着，
能容纳的水就等于sum(water_level-height[i])(i：[l+1,r-1])
但是上面这种情形实际上是考虑(l,r)之间的所有石柱子都比water_level地的情形下，如果中间有一个比water_level高的石柱子呢，
比如[2,0,0，5,0,0，3]这种情形开始l=2,r=3,warer_level=2;但是后来遇到5之后，water_level实际上已经提升为3了，
因此由地的一端开始移动，当遇到比水平面高的柱子时，这是就要更新water_level,重新转换为以上的问题
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int l =0,r=height.size()-1;
        int res = 0;
        while(l<r)
        {
            int water_level = min(height[l],height[r]);//选择较低的柱子作为water_level
            if(water_level==height[l])
            {
                l+=1;//从[l+1,r-1]之间寻找，下一个比water_level高的柱子
                while(l<r&&height[l]<water_level)//比water_level低直接累加(water_level-柱子的高度)
                {
                    res+=(water_level-height[l]);
                    l++;
                }
            }
            else
            {
                r-=1;
                while(l<r&&height[r]<water_level)
                {
                    res+=(water_level-height[r]);
                    r--;
                }
            }
        }
        return res;
    }
};
