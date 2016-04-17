/*
71. Simplify Path  
Difficulty: Medium
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

/*2nd pass:
思路：用栈来保存路径中间的目录，把路径中/ /之间的内容全部抽取出来：
1）如果没有以"/"结尾则在后面添加"/"结尾
2)如果为""或者"."或者".."是不能加入路径的，必须就地处理，""或者"."直接跳过，“..”直接回退
3）最后根据路径栈中的元素重建路径，如果路径本身为空，则返回"/",否则在每个目录前加"/"输出
*/

class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty())
            return path;
        assert(path[0]=='/');//path一定以'/'开头
        int length = path.length();
        if(path[length-1]!='/')
            path+='/';
        int curSlash  = 0,nextSlash = path.find_first_of('/',curSlash+1);
        vector<string> res;
        while(nextSlash!=string::npos)
        {
            string curPath = path.substr(curSlash+1,nextSlash-curSlash-1);
            if(curPath==".."&&!res.empty())//1)能回退就回退,遇到“..”就执行回退流程，不为空就回退；为空就不回退
                res.pop_back();
            else if(curPath!="." && curPath!=""&&curPath!="..")//2)"..","."，" "不能入栈
                res.push_back(curPath);
            curSlash = nextSlash;
            nextSlash = path.find_first_of('/',curSlash+1);
        }
        string ret;
        for(string dir:res)
            ret +=("/"+dir);
        return ret.empty()?"/":ret;
    }
};
