/*
69. Sqrt(x)   
Difficulty: Medium
Implement int sqrt(int x).

Compute and return the square root of x.
*/
//2nd pass
/*
思路：用
x**2-x0 = 0
令:f(x) = x**2-x0
在(x1,x1**2-x0)处求导:2x1
方程: y-(x1**2-x0) = 2x1*(x2-x1)
令 y=0 得；x2 =  (x0+x1**2)/(2*x1)
递归直到x1与x2很接近停止
*/
class Solution {
public:
    int mySqrt(int x) {
        assert(x>=0);
        if(x==0||x==1) return x;
        double x0 = x,x1 = (x+x0*x0)/(2*x0);//注意：这里是double
        while(abs(x1-x0)>1e-6)
        {
            x0 = x1;
            x1 = (x+x0*x0)/(2*x0);
        }
        return int(x0);
    }
};
