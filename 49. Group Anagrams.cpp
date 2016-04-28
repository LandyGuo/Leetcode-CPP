/*
49. Group Anagrams   
Difficulty: Medium
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/
//2nd pass
/*
思路:将所有字符串全部进行排序后作为字符串的原型(key),将具有相同key的字符串放在一起。
最后需要对字符串的vector进行排序
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> sv_map;
        for(string s:strs)
        {
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            sv_map[tmp].push_back(s);
        }
        vector<vector<string>>ret;
        for(auto p = sv_map.begin();p!=sv_map.end();p++)
        {
            sort(p->second.begin(),p->second.end());
            ret.push_back(p->second);
        }
        return ret;
    }
};
