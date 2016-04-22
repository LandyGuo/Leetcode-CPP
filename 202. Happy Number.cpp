/*
202. Happy Number  
Difficulty: Easy
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
/*2nd pass
思路：为防止重复，需要将曾经已经出现的数记录下来，以后再次出现，说明会出现无限循环，则肯定不是
*/

class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        set<int> record;
        while(n!=1)
        {
            if(record.find(n)==record.end())
                record.insert(n);
            else return false;
            n = cal(n);
        }
        return true;
        
        
    }
    
    int cal(int n)
    {
        int sum = 0;
        while(n)
        {
            int digit = n%10;
            sum+=(digit*digit);
            n/=10;
        }
        return sum;
    }
};
