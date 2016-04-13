/*
205. Isomorphic Strings 
Difficulty: Easy
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
/*2nd pass
与第290题思路完全一样，注意建立映射的时候也要一一对应
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> s_t,t_s;
        for(int i=0;i<s.length();i++)
        {
            if(s_t.find(s[i])==s_t.end()&&t_s.find(t[i])==t_s.end())
            {
                s_t[s[i]]=t[i];
                t_s[t[i]]=s[i];
            }
            else if(s_t[s[i]]==t[i] && t_s[t[i]]==s[i])
                continue;
            else
                return false;
        }
        return true;
    }
};
