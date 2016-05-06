/*
9. Palindrome Number  
Difficulty: Easy
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.*/
/*
思路：
//负数不是回文的
分别从高位和低位提取一个整数的所有位数
依次提取一个整数x的低位的方法很常规:x%10,x/=10;循环即可(x/10也可以认为是除数每次*10)
提取一个数的高位：需要根据这个数的位数，来确定对应高位的除数
如:5 8 4 2 1
high :58421 / 10000 %10 = 5 low:58421/1 % 10 = 1
high :58421 / 1000 %10 = 8 low:58421/10 % 10 = 2
high :58421 / 100 %10 = 4 low:58421/100 % 10 = 4
高位除数100 = 低位除数100 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)//负数不是回文的
            return false;
        int largeDiv = 1,smallDiv=1;
        int dpx = x;
        while(dpx/10)
        {
            largeDiv*=10;
            dpx/=10;
        }
        while(largeDiv>smallDiv)
        {
            int large = (x/largeDiv)%10,small = (x/smallDiv)%10;
            if(large!=small)
                return false;
            largeDiv/=10,smallDiv*=10;
        }
        return true;
        
    }
};
