/*
22. Generate Parentheses  
Difficulty: Medium
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
//2nd pass
/*
思路：在每个位置都保持性质:左括号数>=右括号数；即对于剩余的而言：左括号数<=右括号数；
因此有：
剩余的左括号数>右括号数，invalid
剩余的左括号数=右括号数，接下来只能放左括号
剩余的左括号数<右括号数,接下来能放左括号或右括号
知道左括号和右括号都用完为止
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string tmp;
        vector<string>res;
        gen(n,n,tmp,res);
        return res;
    }
    
    void gen(int left,int right,string tmp,vector<string>&res)
    {
        if(left==0&&right==0)
        {
            res.push_back(tmp);
        }
        if(left>right||right<0||left<0)
            return;
        else if(left==right)//只能分配(
            gen(left-1,right,tmp+'(',res);
        else if(left<right)//可以是'('或')'
        {
            gen(left-1,right,tmp+'(',res);
            gen(left,right-1,tmp+')',res);
        }
    }
};
