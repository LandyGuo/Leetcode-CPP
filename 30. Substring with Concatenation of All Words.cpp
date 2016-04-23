/*
30. Substring with Concatenation of All Words   
Difficulty: Hard
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
/*
思路：
因为不用关注词出现的先后顺序，因此可以用词袋模型：
将words中的所有单词及其次数放到一个all_words袋子中，每次从s中一个开始位置start起，往后找words.size()个单词，并用一个新的袋子has_words存储出现的单词及其次数，
如果出现的单词在all_words中找不到，说明当前start找不到，start往后移动重新开始找
*/

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>const& words) {
		vector<int>res;
		if (s.empty())
			return res;
		int word_length = words[0].length();
		if (s.length() < word_length*words.size())
			return res;//一些鲁棒性检查
		unordered_map<string, int>all_words, has_words;
		for (string tmp : words)
			all_words[tmp]++;//all_words统计words中的单词以及出现的次数
		int start = 0;//标识开始寻找的起始位置
		while (start <= s.length() - words.size()*word_length)
		{
			int j = start;
			int i = 0;//在每个start位置起，最多只用往后找words.size()个单词就行了
			for (; i<words.size(); i++)//
			{
				string curStr = s.substr(j, word_length);//依次截取长度为word_length的单词
				if (all_words.find(curStr) == all_words.end())//单词不存在就返回
					break;
				has_words[curStr]++;//单词存在，把当前已有的单词计数+1
				if (has_words[curStr]>all_words[curStr])//某个单词超出能出现的最大次数,invalid
					break;
				j += word_length;//截取下一个长度为word_length的单词
			}
			if (i == words.size())//说明循环完成，把可行的起始位置加入
			    res.push_back(start);
			has_words.clear();
			start++;
		}
		return res;
	}
};
