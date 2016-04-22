/*
38. Count and Say   
Difficulty: Easy
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
/*2nd pass
2 pointers
*/
class Solution {
public:
    string countAndSay(int n) {
        char tmp[32];
        sprintf(tmp,"%d",1);
        string ret = string(tmp);
        for(int i=1;i<n;i++)
            ret = say(ret);
        return ret;
    }
    
    
    string say(string n)
    {
        int p1=0,p2=p1;
        string ret;
        while(p1<n.length())
        {
            int cnt=0;
            while(p2<n.length()&&n[p2]==n[p1])
                cnt++,p2++;
            char tmp[30];
            sprintf(tmp,"%d",cnt);
            ret += string(tmp)+n[p1];
            p1= p2;
        }
        return ret;
    }
};
