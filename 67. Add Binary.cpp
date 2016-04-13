/*
67. Add Binary 
Difficulty: Easy
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
/*2nd pass
思路：
1）两个数a和b相加，所得结果的位数最多为max(a的位数，b的位数)+1,举个栗子：3位数+4位数 999+9999 = 5位数，因此存储a和b对应位的和最多用max(a.length(), b.length()) + 1长度的数组
2) 相加完后由低位到高位统一处理进位
3) 注意最后对结果的处理:除去左边的0
4）将结果转换为字符串拼接起来
*/

class Solution {
public:
	string addBinary(string a, string b) {
		string res = "";
		vector<int> ires(max(a.length(), b.length()) + 1, 0);
		int p1 = a.length() - 1, p2 = b.length() - 1, i = ires.size() - 1;
		while (p1 >= 0 || p2 >= 0)
		{
			int add1 = 0, add2 = 0;
			if (p1 >= 0)
				add1 = a[p1] - '0';
			if (p2 >= 0)
				add2 = b[p2] - '0';
			ires[i] = add1 + add2;
			i--, p1--, p2--;
		}
		//处理进位
		int carry_on = 0;
		for (auto p = ires.rbegin(); p != ires.rend(); p++)
		{
			*p = (*p) + carry_on;
			carry_on = *p / 2;
			*p = (*p) % 2;
		}
		//除去左边的0
		int p = 0;
		while (p < ires.size() && ires[p] == 0)p++;
		if (p == ires.size()) return "0";
		else
		{
			for (int i = p; i < ires.size(); i++)
			{
				char tmp[2];//转换后的字符串最多只有一位（10 或者 00），用2个空间存储
				sprintf(tmp, "%d", ires[i]);//注意这里将整数转换为字符串的方法
				res += string(tmp);
			}
			return res;
		}
	}
};
