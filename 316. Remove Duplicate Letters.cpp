/*
316. Remove Duplicate Letters
Difficulty: Hard
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/
/*2nd pass
1)用used标志位标志当前这个字符有没有出现在栈里(相当于一个map)
2)维护一个当前最小字母序的stack，当前字符加入的时候，移除栈顶所有能移除(??)的比它大的字符————类似一种贪心策略，小字母序的能往前放就尽量往前放
所谓能移除是指：比它大的字符在后面还会出现(如何知道？对每个字符设置一个计数器)
证明：因为对当前字符而言，通过以上策略当前字符最后放的位置已经是最能靠前的位置
3)由2可知,栈始终维持最小字母序，因此如果当前字符在栈中已经存在，可以直接跳过
*/
class Solution {
public:
	string removeDuplicateLetters(string s) {
		int cnt[26] = { 0 };//剩余字符计数器
		unsigned used = 0;//used标识，用低26位标识当前字符是否已经在栈中
		for (auto c : s)//初始化计数器
			cnt[c - 'a'] += 1;
		stack<char> res_stack;
		for (auto c : s)
		{
			cnt[c - 'a']--;//处理到当前字符，字符数减1
			if(res_stack.empty())//栈为空可以直接加入
			{
			   res_stack.push(c);
			   used |= (1 << (c - 'a'));//修改used标志位
			}
			else if((used>>(c-'a')&1)==1)//已经在栈中出现的字符直接跳过
			    continue;
			else
			{//当前字符没出现过，弹出所有比当前字符字母序大的字符，并修改used标志位；然后压入当前字符，修改标志位
				while (!res_stack.empty() && c<res_stack.top() && cnt[res_stack.top() - 'a']>0)
				{
					used &= (~(1 << (res_stack.top() - 'a')));
					res_stack.pop();
				}
				
				res_stack.push(c);
				used |= (1 << (c - 'a'));
			}
		}
		string res = "";
		while (!res_stack.empty())
		{
			res = res_stack.top() + res;
			res_stack.pop();
		}
		return res;
	}
};
