/*
140. Word Break II   
Difficulty: Hard
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
//2nd pass
/*思路：
1）典型的动态规划问题，先用动态规划遍历求字符串结尾是否可达，如果不可达直接返回空
2）在动态规划过程中，保存字符之间可达的信息，方便dfs时根据当前位置，找下一个可达点
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        vector<int>opt(len+1,0);
        vector<vector<int>>choice(len,vector<int>());
        opt[0] = 1;
        for(int i=1;i<opt.size();i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                string cur = s.substr(j,i-j);
                if(opt[j]==1&&wordDict.find(cur)!=wordDict.end())
                {
                    opt[i] = 1;
                    choice[j].push_back(i-1);
                }
            }
        }
        vector<string> ret,path;
        if(opt[len]==0) return ret;//特别注意这里：如果最后不可达的话，就说明不能组成，直接返回
        
        dfs(s,0,path,ret,choice);
        return ret;
    }
    
    void dfs(string s,int start,vector<string>&path,vector<string>&ret,vector<vector<int>>const &choice)
    {
        if(start==s.length())
        {
            string tmp;
            for(int i=0;i<path.size();i++)
            {
                tmp+=path[i];
                if(i!=path.size()-1)
                    tmp+=" ";
            }
            ret.push_back(tmp);
            return;
        }
        for(int next_pos:choice[start])
        {
                path.push_back(s.substr(start,next_pos-start+1));
                dfs(s,next_pos+1,path,ret,choice);
                path.pop_back();
        }
    }
};
