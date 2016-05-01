/*
229. Majority Element II  
Difficulty: Medium
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
/*2nd pass
注意：摩尔计数法的顺序：先判相等，然后判是否需要换元素，最后减支持度；每来一个元素只执行以上3种操作中的一种
思路：同样是摩尔计数法，出现次数大于1/3的最多有两个，因此就找出现次数最多的两个就行了(采用摩尔计数法——真正的解一定包含在摩尔计数法里面，为排除伪答案，需要验证)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ret;
        int major1=INT_MAX ,support1=0;
        int major2=INT_MAX ,support2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(major1==nums[i])//判相等
                support1++;
            else if(major2==nums[i])
                support2++;
            else if(support1==0)//换元素
                major1 = nums[i],support1 = 1;
            else if(support2==0)
                major2 = nums[i],support2 = 1;
            else //减置信度
                support1--,support2--;
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==major1)
                cnt1++;
            else if(nums[i]==major2)
                cnt2++;
        }
        int length = nums.size();
        if(cnt1>length/3)
            ret.push_back(major1);
        if(cnt2>length/3)
            ret.push_back(major2);
        return ret;
    }
};
