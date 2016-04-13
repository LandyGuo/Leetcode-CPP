/*
46. Permutations
Difficulty: Medium
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
/*
思路：记录下开始序列并加入res，然后采用Next Permutation的方法每次产生下个序列和最开始不一致，就加入,一致则说明所有的序列已经生成完了
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res.push_back(nums);//deep copy
        vector<int> start = nums;//deep copy
        getNext(nums);
        while(nums!=start)
        {
            res.push_back(nums);
            getNext(nums);
        }
        return res;
    }
    
    void getNext(vector<int>&nums)
    {
        int p1=nums.size()-2,p2=p1+1;
        while(p1>=0&&nums[p1]>=nums[p2]){p1--,p2--;};
        if(p1==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int k = nums.size()-1;
        while(nums[k]<=nums[p1])k--;
        swap(nums[p1],nums[k]);
        reverse(nums.begin()+p1+1,nums.end());
    }
};
