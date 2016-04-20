/*
12. Integer to Roman   
Difficulty: Medium
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
/*2nd pass 
I(1),V(5),X(10),L(50),C(100),D(500),M(1000)
每次取num的低位，第一次取低位对应ones,第二次取低位对应tens,第三次取低位对应hundreds,第四次取低位对应thousands
将字符串从高位到低位进行拼接即可
*/

class Solution {
public:
    string intToRoman(int num) {
          map<int,string> ones={{1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"}};
          map<int,string> tens={{1,"X"},{2,"XX"},{3,"XXX"},{4,"XL"},{5,"L"},{6,"LX"},{7,"LXX"},{8,"LXXX"},{9,"XC"}};
          map<int,string> hundreds={{1,"C"},{2,"CC"},{3,"CCC"},{4,"CD"},{5,"D"},{6,"DC"},{7,"DCC"},{8,"DCCC"},{9,"CM"}};
          map<int,string> thousands = {{1,"M"},{2,"MM"},{3,"MMM"},{4,"MMMM"}};
          vector<map<int,string>> digits = {ones,tens,hundreds,thousands};
          int i = 0;
          string res;
          while(num)
          {
              int cur_digit = num%10;
              res = digits[i++][cur_digit]+res;
              num/=10;
          }
          return res;
    }
};
