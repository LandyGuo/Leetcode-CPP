/*
187. Repeated DNA Sequences  
Difficulty: Medium
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
Subscribe to see which companies asked this question
*/
/*2nd pass
思路：位编码 ATCG每个用2个比特表示,这样10个长度的序列用20bit表示即可
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        if(s.length()<=10)
            return res;
        unordered_map<int,int>cnt;
        int base = 0;
        for(int i=0;i<10;i++)
            base = ((base<<2)&0xfffff)|encode(s[i]);
        cnt[base] = 1;
        for(int i=10;i<s.length();i++)
        {
            base = ((base<<2)&0xfffff)|encode(s[i]);
            if(cnt.find(base)==cnt.end())
                cnt[base] =1;
            else 
                cnt[base]+=1;
            if(cnt[base]>=2)
            {   
                string tmp = s.substr(i-9,10);
                res.push_back(tmp);
                cnt[base] = INT_MIN;//避免重复加入
            }
        }
        return res;
        
    };
    
    int encode(char c)
    {
        int res;
        switch(c)
        {
            case 'A':res= 0;break;
            case 'T':res= 1;break;
            case 'C':res= 2;break;
            case 'G':res= 3;break;
        }
        return res;
    };
};
