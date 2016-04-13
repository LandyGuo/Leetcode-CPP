/*
324. Wiggle Sort II My Submissions QuestionEditorial Solution
Total Accepted: 8230 Total Submissions: 37403 Difficulty: Medium
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
//思路：先排序，从大到小依次填充完奇数位之后，再填充偶数位
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> m_nums = nums;
        sort(m_nums.begin(),m_nums.end(),[](int&a,int&b)->bool{return a<b;});//从小到大排序
        for(int i = 1;i<nums.size();i+=2)//填充奇数位，1,3,5,...
        {
            nums[i] = m_nums.back();
            m_nums.pop_back();
        }
        for(int i = 0;i<nums.size();i+=2)//填充偶数位，0,2,4,...
        {
            nums[i] = m_nums.back();
            m_nums.pop_back();
        }
        
    }
};
/*
Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
//Using index-rewriting


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> m_nums = nums;
        //find median
        int median = -1;
	    if (nums.size() % 2 == 0)
		    median = (findKthElem(nums, nums.size() / 2) + findKthElem(nums, nums.size() / 2 + 1)) / 2;
	    else
		    median = findKthElem(nums, (nums.size() + 1) / 2);
		  //index rewriting
		  #define A(i)  (nums[(2*(i)+1)%(nums.size()|1)])
		  //three-way sort
		  int i=0,j=0,k=nums.size()-1;
		  while(j<=k)
		  {
		    if(A(j)>median)//j往前行进的条件是A(j)>median 或 A(j)=median;j之前都>=median
		    {
		        swap(A(i),A(j));
		        i++,j++;
		    }
		    else if(A(j)<median)//k往后行进的条件是:A(j)<median,k之后都<median
		    {
		        swap(A(j),A(k));
		        k--;
		    }
	        else
	            j++;
		  }
    }
    
    int findKthElem(vector<int> const &nums,int k)
    {
    	int pivot = nums[rand()%nums.size()];
    	vector<int> lessThanK, geThanK;
    	for (auto num : nums)
    	{
    		if (num < pivot)
    			lessThanK.push_back(num);
    		else if (num>pivot)
    			geThanK.push_back(num);
    	}
    	int lt_pivot_num = lessThanK.size(), ge_pivot_num = geThanK.size();
    	if (k <= ge_pivot_num)
    		return findKthElem(geThanK, k);
    	else if (k > nums.size() - lt_pivot_num)
    		return findKthElem(lessThanK, k - (nums.size() - lt_pivot_num));
    	else
    		return pivot;
    };
};



