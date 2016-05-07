/*
17. Letter Combinations of a Phone Number  
Difficulty: Medium
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

//2nd pass
//标准的回溯法+dfs
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty())
            return ret;
        vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        dfs(digits,0,"",ret,map);
        return ret;
    }
    
    void dfs(string digits,int index,string path,vector<string>&res,vector<string>const &map)
    {
        if(index==digits.length())
        {
            res.push_back(path);
            return;
        }
        string choices = map[digits[index]-'0'];
        for(char c:choices)
            dfs(digits,index+1,path+c,res,map);
    }
};
