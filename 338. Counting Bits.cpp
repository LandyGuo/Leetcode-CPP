/*
338. Counting Bits   
Difficulty: Medium
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
/*2nd pass
思路：在前面的基础上
 * 0000 0 
 * -------------
 * 0001 1        在前面的基础上+1
 * --------------------1）
 * 001-0 1              与前2个低位一样，在前2个基础上+1
 * 001-1 2          
 * -----------------------
 * 0100 1
 * 0101 2
 * 0110 2               与前4个低位一样,在前4个基础上+1
 * 0111 3
 * --------------------2）
 * 1-000 1
 * 1-001 2              
 * 1-010 2
 * 1-011 3
 *                       与前8个低位一样,在前8个基础上+1
 * 1-100 2
 * 1-101 3
 * 1-110 3
 * 1-111 4
 * ----------------------------3）
 * 
*/
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int>res(num+1, 0);
		if (num == 0)
			return res;
		int i = 1;
		while (i <= num)
		{
			int cur_size = i;
			for (int j = 0; i <=num&&j < cur_size; j++)
			{
				res[i]=res[j] + 1;
				i++;
			}
		}
		return res;
	}
};
