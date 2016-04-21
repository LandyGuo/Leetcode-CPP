/*
204. Count Primes   My Submissions QuestionEditorial Solution
Total Accepted: 60749 Total Submissions: 250645 Difficulty: Easy
Description:

Count the number of prime numbers less than a non-negative number, n.
*/
/*2nd pass
思路：用淘汰法，开始时将除了0和1以外的数都默认为质数，然后每当遇到一个质数，执行以下的淘汰规则：
    如果i是质数，那么i*i+j*i(j=0,1,2,3...)都不可能是质数，因此2是质数，4不是质数，6也不是.。。
淘汰完，剩下的就都是质数，
注意：i*i<n即可将小于n的所有非质数淘汰完，否则i*i太大可能会溢出
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        vector<int>flags(n,1);
        flags[0] = flags[1] = 0;//2 prime
        int i = 2;
        while(i*i<n)
        {
            if(flags[i])
            {
                int j = 0;
                while(i*i+j*i<n)
                    flags[i*i+(j++)*i] =0;
                
            }
            i++;
        }
        int sum = 0;
        for(int c:flags)
            sum+=c;
        return sum;
    }
};
