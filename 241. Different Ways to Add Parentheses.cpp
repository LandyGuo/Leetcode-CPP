/*
241. Different Ways to Add Parentheses 
Difficulty: Medium
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
//2nd pass
/*
思路：遍历字符串，每当遇到符号就递归进行拆分
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>res;
        for(int i=0;i<input.length();i++)
        {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*')//每当遇到符号就拆分
            {
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1,input.length()-i));
                for(auto l:left)
                {
                    for(auto r:right)
                    {
                        int tmp = 0;
                        switch(input[i])
                        {
                            case '+':tmp = l+r;break;
                            case '-':tmp = l-r;break;
                            case '*':tmp = l*r;break;
                        }
                        res.push_back(tmp);
                    }
                }
            }
        }
        if(res.empty())//res为空说明整个input是一个数，中间没有符号，这时将整个字符串转换为数字
            res.push_back(atoi(input.c_str()));
        return res;
    }
};
