/*
1. Two Sum   
Difficulty: Easy
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/
//2nd pass
//思路：用map保存<target-num,cur_index>(下个想要的数，当前的索引)，当新来与target-num相同的数时，返回map[cur],cur_index即可

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int,int> imap;
        for(int i=0;i<nums.size();i++)
        {
            if(imap.find(nums[i])==imap.end())
                imap[target-nums[i]] = i;
            else
            {
                res.push_back(imap[nums[i]]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
    
};
