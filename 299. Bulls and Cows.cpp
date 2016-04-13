/*
299. Bulls and Cows 
Difficulty: Easy
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/
/*2nd pass:
思路：
1）统计guess里面每个字符出现的次数
2) 在secret里面遍历,如果c在guess里面出现，则加1分，然后Guess[c]的可用分数-1 ，最终得到B=bulls+cows
3)bulls的计算很简单，直接遍历一遍得到A,cows=B-A

*/
class Solution {
public:
    string getHint(string secret, string guess) {
        int B=0,A=0;
        int num[10]={0};
        for(char c:guess)//统计guess里面出现的次数
            num[c-'0']++;
        for(char c:secret)
        {
            if(num[c-'0']!=0)
            {
                B++;
                num[c-'0']--;
            }
        }
        for(auto p1=secret.begin(),p2=guess.begin();p1!=secret.end()&&p2!=guess.end();p1++,p2++)
        {
            if(*p1==(*p2))
                A+=1;
        }
        B-=A;
        char buff[32];
        sprintf(buff,"%dA%dB",A,B);
        return string(buff);
    }
};
