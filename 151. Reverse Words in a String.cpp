/*
151. Reverse Words in a String  
Difficulty: Medium
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/
/*2nd pass
从后往前处理，先跳过空格，然后用临时栈收集单词，从临时栈中弹出word放到sentence中；然后重复以上操作
*/
class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty())
			return;
		stack<char> word;
		vector<string> sentence;
		int p = s.size() - 1;
		while (p >= 0)
		{
			while (p >= 0 && s[p] == ' ')p--;//去空
			while (p >= 0 && s[p] != ' ')//collect words
			{
				word.push(s[p]);
				p--;
			}
			if (word.empty())//没有收集到word就返回
				break;
			string cur_word = "";//restore word
			while (!word.empty())
			{
				cur_word += word.top();
				word.pop();
			}
			sentence.push_back(cur_word);
			sentence.push_back(" ");
		}
		string res = "";
		if(sentence.empty())//没有收集到word就返回
		{
		    s = "";
		    return;
		}
		for (int i = 0; i != sentence.size() - 1; i++)
			res = res + sentence[i];
		s = res;
	}
};
