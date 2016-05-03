/*
6. ZigZag Conversion  
Difficulty: Easy
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
Subscribe to see which companies asked this question
*/
//2nd pass
//思路：用一个指针上下移动，将不同的字符依次分配到不同的bin中
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string>bins(numRows,"");
        int i=0,bin_num=0;
        bool flag = true;
        while(i<s.length())
        {
            bins[bin_num] += s[i];
            i++;
            bin_num = flag?bin_num+1:bin_num-1;
            if(bin_num==numRows)
            {
                bin_num=numRows-2;
                flag = false;
            }
            if(bin_num==-1)
            {
                bin_num=1;
                flag = true;
            }
        }
        string ret;
        for(string tmp:bins)
            ret+=tmp;
        return ret;
    }
};
