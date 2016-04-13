/*
319. Bulb Switcher My Submissions QuestionEditorial Solution
Total Accepted: 16191 Total Submissions: 40249 Difficulty: Medium
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/
/*pass2:
思路：
翻转奇数次，灯亮；偶数次，灯灭；
从1开始每个乘数因子都会翻转一次，如果有奇数个质因子，最后灯就会亮；
但是质因子一般都是成对出现的，如6的质因子(2,3)，也就是说质因子应该都是偶数个；
但如果两个质因子相同(完全平方数)的话，这时质因子就是奇数个，如4的质因子(1,4),(2,2),有3个质因子~
因此，即统计从[1,n]有多少个完全平方数
*/

class Solution {  
public:  
    int bulbSwitch(int n) {
        if(n==0)
            return 0;
        int res = 0,i=1;
        while(i*i<=n)
        {
            i+=1;
            res+=1;
        }
        return res;
            
        
    }  
};
