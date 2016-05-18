/*
127. Word Ladder
Difficulty: Medium
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
//2nd pass
/*思路：
1）bfs 类似于寻找最短路径，如果用dfs会超时
2）层序遍历时，不断找到下一层可达的节点，如果节点在当前层已经出现过了，那么节点不可能在下一层出现，因为如果出现，路径肯定比
    该节点出现在当前层长
3）层序遍历时统计当前所在的层数
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if(beginWord==endWord) return 1;
        queue<string> q;
        q.push(beginWord);
        wordList.erase(beginWord);
        int level = 1,cnt=1;
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();
            cnt--;
            for(int i=0;i<cur.length();i++)
            {
                for(int j='a';j<='z';j++)
                {
                    char tmp = cur[i];
                    cur[i] = j;
                    if(cur==endWord)
                        return level+1;
                    if(wordList.find(cur)!=wordList.end())
                    {
                        q.push(cur);
                        wordList.erase(cur);
                    }
                    cur[i] = tmp;
                }
            }
            if(cnt==0)
            {
                level+=1;
                cnt =q.size();
            }
        }
        return 0;
    }
    
};
