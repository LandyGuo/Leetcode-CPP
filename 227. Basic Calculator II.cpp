/*
227. Basic Calculator II  
Difficulty: Medium
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
*/
/*
思路：把"+-"视为单目运算符，就是下一个运算数的符号；把乘除视为双目运算符，就是两个数之间的操作
没有乘除时，把所有的运算数与之前面的符号视为一个有符号数，直接压入栈
这样：当有乘除的时候，先计算弹出上一个入栈的有符号数，然后和当前的有符号数进行乘除运算，然后再压入栈~
所以：现在问题的核心转为如何从一个表达式中提取所有带符号的操作数：
1)初始操作数的默认运算符为+，知道遇到'-'改变默认运算符
2)提取数字完后，和当前的运算符一起构成一个有符号数，然后判断有没有乘除：如果有乘除，出栈运算后入栈，然后清除乘除标志位，把当前符号设置为正；
没有乘除，直接入栈，把当前符号设置为正！！（注意：也就是说，只要发生一次入栈，符号标志位都必须回正，因为符号只作用于当前操作数，如果是因为乘除入栈，还得清楚乘除标志位）
3)最后将栈里面的所有数进行累加
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> add_nums;
        int op1=1,op2=0;//op1 :1_+正号,-1负号_-//op2:0：没有乘除运算符  1_*乘法,2_/除法
        int p=0;
        while(p<s.length())
        {
            if(s[p]>='0'&&s[p]<='9')
            {
                int cur_num = 0;
                while(p<s.length()&&s[p]>='0'&&s[p]<='9')
                {
                    cur_num*=10;
                    cur_num+=(s[p]-'0');
                    p++;
                }
                if(op2==0)//当前没有乘除
                {
                    add_nums.push(op1*cur_num);
                    op1=1;//加完一个数就把运算符回正，表示这个运算符只对当前数字有效
                }
                else
                {
                    int last = add_nums.top();
                    add_nums.pop();
                    if(op2==1)//*
                        add_nums.push(last*op1*cur_num);
                    else 
                        add_nums.push(last/(op1*cur_num));
                    op2 = 0;//清楚乘除标志位
                    op1 = 1;//对符号进行回正
                }
            }
            else if(s[p]=='+'||s[p]=='-')
            {
                op1= (s[p]=='+')?1:-1;
                p++;
            }
            else if(s[p]=='*'||s[p]=='/')
            {
                op2 = (s[p]=='*')?1:2;
                p++;
            }
            else//空格
                p++; 
        }
        int res = 0;
        while(!add_nums.empty())
        {
            res+=add_nums.top();
            add_nums.pop();
        }
        return res;
        
    }
};
