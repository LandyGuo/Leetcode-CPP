/*
165. Compare Version Numbers   
Difficulty: Easy
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
	int compareVersion(string version1, string version2) {
		size_t pos1 = version1.find_first_of("."), pos2 = version2.find_first_of('.');//string.find_first_of返回的是位置，不是iterator
		string::iterator p1 = ((pos1 == string::npos) ? version1.end() : version1.begin() + pos1),
			p2 = ((pos2 == string::npos) ? version2.end() : version2.begin() + pos2);
		int res_1 = convert(version1.begin(), p1), res_2 = convert(version2.begin(), p2);
		p1 = (p1 == version1.end()) ? p1 : p1 + 1;//注意这里：如果已经指向字符串结尾就不能再往后移动了
		p2 = (p2 == version2.end()) ? p2 : p2 + 1;
		if (res_1 == res_2&&p1 == version1.end() && p2 == version2.end())
			return 0;
		else if (res_1 > res_2)
			return 1;
		else if (res_1 < res_2)
			return -1;
		else
			return compareVersion(string(p1, version1.end()), string(p2, version2.end()));
	}


	int convert(string::iterator p1, string::iterator p2)//字符串转整数
	{
		int res = 0;
		while (p1 != p2)
		{
			res *= 10;
			res += (*p1-'0');
			p1++;
		}
		return res;
	}
};
