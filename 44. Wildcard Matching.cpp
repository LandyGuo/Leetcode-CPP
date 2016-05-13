/*
44. Wildcard Matching   
Difficulty: Hard
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
//2nd pass
/*
思路：
将s先匹配完，当s匹配完时模板串只能剩下"*",否则就不匹配
注意：在匹配过程中，正常匹配:p1与p2指向相等或p2指向'?'
                    回溯匹配:p2指向'*'
                    不匹配：可回溯
                    不匹配：不能回溯，返回false
*/
#define min(x,y) ((x<=y)?(x):(y))
class Solution {
public:
	bool isMatch(string s, string p) {
		int p1 = 0, p2 = 0;
		int p1_back=-1,p2_back=0;
		while (p1 < s.length())//将s作为滑动的依据，当s全部匹配完时，如果p没有匹配完，这时p剩下的一定全部都是*
		{
		    if(s[p1]==p[p2]||p[p2]=='?')//正常匹配的情形
		        p1++,p2++;
		    else if(p[p2]=='*')//每当出现*时就会添加回溯
		        p1_back = p1,p2_back = p2++;//record
		    else if(p1_back!=-1&&p1_back<s.length())//不匹配，能回溯
		    {
		        p1 = ++p1_back;
		        p2 = p2_back;
		    }
		    else//不匹配，不能回溯
		        return false;
	    }
	    while(p2<p.length()&&p[p2]=='*')p2++;//s匹配完成后，去掉p后面所有的*,看p2能不能走到结尾
	    return p2==p.length();
	}
};
