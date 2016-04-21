/*
219. Contains Duplicate II   
Difficulty: Easy
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
//2nd pass 注意：update last appear index
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> record;
        for(int i = 0;i<nums.size();i++)
        {
            if(record.find(nums[i])==record.end())//not find
            {
                 record.insert({nums[i],i});
                 continue;
            }
            else//find
            {
                if(i-record[nums[i]]<=k)//check distance
                    return true;
                record[nums[i]] = i;//update last appear index
            }
        }
        return false;
    }
};
