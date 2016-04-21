/*
190. Reverse Bits  
Difficulty: Easy
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/
/*2nd pass:
每次取最低位，把最低位往高位移动实现翻转
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ret = 0;
        for(int i=0;i<32;i++)
        {
            int lowbit = n&1;
            ret |= (lowbit<<(31-i));
            n>>=1;
        }
        return ret;
        
    }
};
