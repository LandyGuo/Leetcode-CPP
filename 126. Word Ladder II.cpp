/*
126. Word Ladder II
Difficulty: Hard
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#define min(x,y)  ((x<=y)?(x):(y))
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<vector<string>> ret, levels;
		queue<string> q;
		q.push(beginWord);
		vector<string> levelWord;
		int cnt = 1, level = 1, finalLevel = wordList.size() + 2;//最大的单词长度
		while (!q.empty() && level <= finalLevel)//特别注意这里：如果当前层能到达end,那么就到当前层word收集完为止
		{
			string cur = q.front();
			q.pop();
			cnt--;
			levelWord.push_back(cur);
			for (int i = 0; i < cur.length(); i++)
			{
				for (int j = 'a'; j <= 'z'; j++)
				{
					if (j == cur[i])continue;
					char tmp = cur[i];
					cur[i] = j;
					if (cur == endWord) finalLevel = min(level, finalLevel);//不断更新最小的长度，超过最小长度一概剪枝
					if (wordList.find(cur) != wordList.end())
					{
						q.push(cur);
						wordList.erase(cur);
					}
					cur[i] = tmp;
				}
			}
			if (cnt == 0)
			{
				levels.push_back(levelWord);
				levelWord.clear();
				cnt = q.size();
				level++;
			}
		}
		//回溯：从endWord开始回溯在levels里面找beginWord
		vector<string> path(1, endWord);
		dfs(endWord, levels, levels.size() - 1, beginWord, path, ret);
		return ret;
	}

	void dfs(string curWord, vector<vector<string>>const&levels, int level, string const & beginWord, vector<string>&path, vector<vector<string>>& ret)
	{
		if (curWord == beginWord)
		{
			vector<string> tmp = path;
			reverse(tmp.begin(), tmp.end());
			ret.push_back(tmp);
			return;
		}
		for (string const & nextWord : levels[level])
		{
			if (cal_distance(curWord, nextWord) <= 1)
			{
				path.push_back(nextWord);
				dfs(nextWord, levels, level - 1, beginWord, path, ret);
				path.pop_back();
			}
		}
	}

	int cal_distance(string const & a, string const & b)
	{
		assert(a.length() == b.length());
		int dis = 0;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] != b[i])dis++;
		}
		return dis;
	}
};
