/*
290. Word Pattern  
Difficulty: Easy
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
/*2nd pass
注意1：string.find_first_of返回的是整数，不是迭代器，找不到时返回string::npos是个很大的整数
注意2：映射的建立必须同步
*/
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> p_s;
		map<string, char> s_p;
		vector<string> strVec;
		auto start = 0;
		while (start <str.length())
		{
			auto end = str.find_first_of(' ', start);
			if (end == string::npos)
				end = str.length();//易错点1：字符串的查找返回的是pos，不是迭代器，如果是string::npos的话就相当于一个很大的数，下面的步骤会报错
			string tmp(str.begin() + start, str.begin() + end);
			strVec.push_back(tmp);
			start = end + 1;
		}
		if (strVec.size() != pattern.length()) return false;
		for (int i = 0; i < strVec.size(); i++)
		{
			if (s_p.find(strVec[i]) == s_p.end()&&p_s.find(pattern[i])==p_s.end())//注意2：这里是易错点：建立映射时必须同时找不到
			{
				s_p[strVec[i]] = pattern[i];
				p_s[pattern[i]] = strVec[i];
			}
			else if (s_p[strVec[i]] == pattern[i] && strVec[i] == p_s[pattern[i]])//或者同时都在映射里
				continue;
			else
				return false;
		}
		return true;
	}
};
