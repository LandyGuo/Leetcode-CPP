/*
228. Summary Ranges 
Difficulty: Medium
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/
/**
 *2pass
 * 双指针法:
 * p1为主指针，p2为辅助指针
 * p1指向当前start的字符，p2从p1处开始往后移动，直到不连续；同时用cnt纪录移动过程中的数个数，如果为1，就只有start;
 * 如果不为1，那么既有start,又有end；
*/
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int p1, p2;
		p1 = p2 = 0;
		while (p1 < nums.size())
		{
			int start = p1;
			p2 = p1;
			int cnt = 0;
			while (p2 < nums.size() && nums[p2] == nums[p1] + cnt)
			{
				cnt++;
				p2++;
			}
			char start_str[32], end_str[32];
			sprintf(start_str, "%d", nums[start]);
			p2--;
			sprintf(end_str, "%d", nums[p2]);
			string start_part(start_str), end_part(end_str);//注意这里将数字转换为字符串的方法
			string tmp_res = "";
			if (cnt != 1)//has start and end
				tmp_res = start_part + "->" + end_part;
			else//only has start
				tmp_res = start_part;
			res.push_back(tmp_res);
			p1 = p2+1;//更新p1为上一个区间结束的下一个位置
		}
		return res;
	}
};
