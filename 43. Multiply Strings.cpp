/*
43. Multiply Strings  
Difficulty: Medium
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/
/*2nd pass
思路：长度为len1的数与长度为len2的数相乘，最终结果的长度最多为len1+len2
因此开辟一个len1+len2长的数组
如果：
res[p1+p2] = nums[p1]*nums[p2]
那么最低位为 len1-1+len2_1,最低位后面有一个空格，但是我们想让这个空格留给进位用，因此将
res[len1+len2-2-(p1+p2)] = nums[p1]*nums[p2]
这样，res的最左边为低位，最右边为高位；高位的右边有一个空格用来处理进位
依次从左向右处理进位，然后去掉高位的0，最终结果反向输出
*/

class Solution {
public:
	string multiply(string num1, string num2)
	{
		int len1 = num1.length(), len2 = num2.length();
		vector<int>res(len1 + len2, 0);
		for (int p1 = len1 - 1; p1 >= 0; p1--)
		for (int p2 = len2 - 1; p2 >= 0; p2--)
			res[len1+len2-2-(p1 + p2)] += (num1[p1] - '0')*(num2[p2] - '0');//低位的运算结果放低位，高位的运算结果放高位
		//从低位到高位处理进位
		int carry_on = 0;
		for (int p = 0; p <res.size(); p++)
		{
			res[p] += carry_on;
			carry_on = res[p] / 10;
			res[p] = res[p] % 10;
		}
		//去掉高位右边的0
		int p = res.size()-1;
		while (p >=0 && res[p] == 0)p--;
		vector<int>finalRes(res.begin(), res.begin()+p+1);
		string ret;
		for (auto q = finalRes.rbegin();q!=finalRes.rend();q++)
		{
			char tmp[2];
			sprintf(tmp, "%d", *q);
			ret += string(tmp);
		}
		return ret.empty() ? "0" : ret;
	}
};
