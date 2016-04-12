/*
307. Range Sum Query - Mutable 
Difficulty: Medium
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
class NumArray {
private:
    vector<int> C;
    vector<int> m_nums;
public:
    NumArray(vector<int> &nums) {
        int length = nums.size();
        C.resize(length+1,0);//resize
        m_nums = nums;//deepcopy
        for(int i=0;i<nums.size();i++)
            add(i+1,nums[i]);
    }
    
    int lowbit(int n)//树状数组父节点到子节点之间的步长差
    {
        return n&(-n);
    }
    
    void add(int k,int val)
    {
        while(k<=C.size()-1)
        {
            C[k]+=val;
            k+=lowbit(k);//找父节点
        }
    }
    
    int getSum(int k)//sum for [0,n]
    {
        int sum = 0;
        while(k>0)
        {
            sum+=C[k];
            k-=lowbit(k);//找子节点
        }
        return sum;
    }

    void update(int i, int val) {
        int diff = val-m_nums[i];
        m_nums[i] = val;
        if(diff)
            add(i+1,diff);
    }

    int sumRange(int i, int j) {
        return getSum(j+1)-getSum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
