/*
224. Basic Calculator 
Difficulty: Hard
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/
/*思路：
1）因为只有"+","-"和括号运算，没有乘除，所以运算符的优先级仅仅由括号决定，否则从左算到右
因此，先解决的第一个问题就是，如何计算一个不含括号，只有加减的表达式?如：“-11+2-4+3”
方法：把所有的数不管正负，全都看成带上符号的操作数：(-11)+(+2)+(-4)+(+3)
用res表示当前操作数,op存储下一个操作数的符号:初始化：res =0,op=1
那么执行计算的过程：
cur=- 是符号 op=-1 res = 0
cur=1 是数字，继续往后读
cur=1 是数字，继续往后读，后面不是数字，cur=11,当前计算结果：res+=(-1*11) ,op=-1,res=-11
cur=+ 是符号，op=1,res=-11
cur=2 是数字，res+=op*cur;res+=(1*2) res=-9
cur=- 是符号，op=-1
cur=4 是数字，后面没有数字，res+=(op(-1)*cur(4)) res = -9-4=-13
cur=+ 是符号, op=1
cur=3 是数字，后面没有数字，res+=(op(1)*cur(3)) res=-13+3 = -10
最终结果为 -10
2)知道以上怎么计算了后，如果有括号，借助栈，将前面的res和op分别压入栈，重置res=0,op=1，开始计算括号里面的值；
如果遇到")"就知道当前括号里面的已经计算完了~ 然后把前一个入栈的res_pre 和 op_pre出栈，那么res = res_pre+op_pre*cur_res(括号里面的计算结果)
重点：每当遇到(就相当于重新开始一轮计算
3)需要注意的是：有效的字符有数字，'+','-','(',')',遇到空格需要直接跳过不处理
*/

class Solution {
public:
	int calculate(string s) {
		stack<int> tmp_res;
		int res = 0, op = 1;//op是当前数的操作符,默认为+
		int p = 0;
		while (p < s.length())
		{
			if (s[p] >= '0'&&s[p] <= '9')//数字
			{
				//获取操作数，并将操作数由char转换为数字
				int cur = 0;
				while (p < s.length() && s[p] >= '0'&&s[p] <= '9')
				{
					cur *= 10;
					cur += (s[p] - '0');
					p++;
				}
				//直接对操作数进行运算
				res += op*cur;
			}
			else if (s[p] == '+' || s[p] == '-')// +,-:修改操作符
			{
				op = (s[p]=='+'?1:-1);
				p++;
			}
			else if (s[p] == '(')//对"("以前的结果压栈
			{
				tmp_res.push(res);
				tmp_res.push(op);
				res = 0, op = 1;//重置，相当于每当遇到'('重新开始计算
				p++;
			}
			else if (s[p] == ')')//，说明括号里面已经计算完了，把括号里面的结果和前一次入栈((之前的操作数和操作符(当前（）计算结果的符号))进行运算
			{
				int last_op = tmp_res.top();
				tmp_res.pop();
				int last_res = tmp_res.top();
				tmp_res.pop();
				res = last_res + last_op*res;
				p++;
			}
			else if(s[p]==' ')//对空格不处理
			    p++;
		}
		return res;

	}
};
