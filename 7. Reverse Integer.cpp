/*
7. Reverse Integer  
Difficulty: Easy
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
//2nd pass
//思路：
//    在转换之前先判断其是否会溢出，如果溢出一概返回0
//注意：INT_MIN转换为整数时，仍然为INT_MIN;有符号数溢出为INT_MIN,无符号数溢出为0 
//实际上题目的意思是：判断符号后，将其当做一个无符号数来看待
class Solution {
public:
	int reverse(int x) {
		bool positive = true;
		if (x < 0)
		{
			positive = false;
			x = -x;
			if (x < 0)//x==INT_MIN时，x=-x,仍然溢出，等于它本身
				return 0;
		}
		int res = 0,next_digit=x%10;
		while (x)
		{
			if (res <= (INT_MAX-next_digit)/10)//重点，在转换时判断是否溢出，如果溢出则认为结果为0，预警机制
			{
				res = res * 10 + next_digit;
				x /= 10;
				next_digit = x % 10;
			}
			else return 0;
		}
		return positive ? res : -res;
	}
};
