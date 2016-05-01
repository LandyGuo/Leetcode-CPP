/*
318. Maximum Product of Word Lengths  
Difficulty: Medium
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/
//2nd pass
/*
注意：特别需要注意运算符优先级：关系运算符>逻辑运算符;这里一定要加括号！！
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int words_len = words.size();
        vector<int> wordbit(words_len,0);
        for(int i=0;i<words_len;i++)
        {
            int cur = 0;
            for(char c:words[i])
                cur |=(1<<(c-'a'));
            wordbit[i] = cur;
        }
        int max_val = 0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((wordbit[i]&wordbit[j])==0)//特别需要注意运算符优先级：关系运算符>逻辑运算符;这里一定要加括号！！
                {
                    int size = (words[i].length())*(words[j].length());
                    max_val = max(max_val,size);
                }
                    
            }
        }
        return max_val;
    }
};
