/*
335. Self Crossing 
Difficulty: Hard
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2],
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)
Example 2:
Given x = [1, 2, 3, 4],
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)
Example 3:
Given x = [1, 1, 1, 1],
┌───┐
│   │
└───┼>

Return true (self crossing)

*/
/*2nd pass
 思路：
        1）总结出相交的模式，然后依次轮流判断是否满足
        1 2 3 4 5 2 8 7
        ->判断 1 2 3 4 5 2 不满足模式
        ->判断 2 3 4 5 2 8 不满足模式
        ->判断 3 4 5 2 8 7 不满足模式
        ->判断 4 5 2 8 7 0 不满足模式
        ->判断 5 2 8 7 0 0 不满足模式
        ....
        2)每6个数为一组表示一个模式:
                    b                              b
   +----------------+             +----------------+
   |                |             |                |
   |                |             |                | a
 c |                |           c |                |
   |                | a           |                |    f
   +----------->    |             |                | <----+
            d       |             |                |      | e
                    |             |                       |
                                  +-----------------------+
                                                   d
        1）d从左边与a相交                2）f从右边与a相交
        
        相交分为以上2种情况:
        1)第一种情况需要4条线，第二种情况需要6跳线；为统一起见，6个数判定一次，4跳线相交的模式可以认为e=f=0(补0)
        2)a,b,c三条线不管怎么都不会相交,因此约束条件从第4跳线d开始
        3)以上两种情形都要求:d>=b>0(注意b=0说明是补的0，这时不能认为是模式),为保证d能交上a:a>=c ;为保证f能交上a: a>=c-e and f>=d-b

*/
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) 
    {
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        for (int i=x.size()-1;i>=0;i--) //逆序判定（为了便于实现，正序也可）
        {
            f = e; e = d; d = c; c = b; b = a; a = x[i];
            if(ValidPattern(a,b,c,d,e,f))
                return true;
        }
        return false;
    }

    bool ValidPattern(int a,int b,int c,int d,int e,int f)//相交模式
    {
        return (d>=b&&b>0) &&( (a>=c&&c>0) or ((a>=c-e)&&(c-e>0)  && (f>=d-b)&&(d-b>=0) ));
    }


};





