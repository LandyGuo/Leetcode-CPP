/*
242. Valid Anagram  
Difficulty: Easy
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
//2nd pass
/*
用Map存储s中每个字符的出现次数，然后遍历T,每出现一个字符将出现的字符次数-1，最后所有的出现次数应该都为0
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int dict[256]={0};
        for(char c:s)
            dict[c]++;
        for(char c:t)
        {
            if(dict[c]>=1)//检验每个字符的出现次数
                dict[c]--;
            else
                return false;
        }
        for(int i=0;i<256;i++)//检验S中的字符是否都在t中出现
        {
            if(dict[i]!=0)
                return false;
        }
        return true;
    }
};
