/*
139. Word Break  
Difficulty: Medium
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
/*2nd pass
思路：动态规划
如果当前单词能够被在wordDict里面的单词组成，那么当前单词就认为是可达的,否则认为不可达
典型的动态规划问题：当前单词是否可达，由当前单词之前的单词的可达性和之前到当前之间的单词是否在字典里面组成；
opt[i] = opt[j]&&s[j,i] in wordDict(0<=j<i)
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> opt(s.length()+1,false);
        opt[0] = true;
        for(int i=1;i<opt.size();i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                opt[i] = opt[j]&&(wordDict.find(s.substr(j,i-j))!=wordDict.end());
                if(opt[i]) break;
            }
        }
        return opt[s.length()];
    }
};
