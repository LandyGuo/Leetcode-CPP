/*
278. First Bad Version  
Difficulty: Easy
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
/*
//一般的二分查找
//如果存在:mid即为target的位置，
//如果不存在:l即为target应该插入的位置,或第一个>target的位置
 int binarySearch(vector<int>&nums,int target)
 {
     int l = 0, r = nums.size() - 1, mid = l + (r - l) / 2;
     while (l <= r)
     {
         if (nums[mid] < target)
             l = mid + 1;
         else if (nums[mid] == target)
             return mid;
         else
             r = mid - 1;
         mid = l + (r - l) / 2;
     }
     return -1;
 }

 //查找最左边界的二分查找
 //将>=target的合并
 int BinarySearchLeft(vector<int>&nums, int target)
 {
     int l = 0, r = nums.size() - 1, mid = l + (r - l) / 2;
     while (l <= r)
     {
         if (nums[mid] < target)
             l = mid + 1;
         else
             r = mid - 1;
         mid = l + (r - l) / 2;
     }
     return (nums[l] == target)?l:- 1;
 }

 //查找最右边界的二分查找
 //将<=target的合并
 int BinarySearchRight(vector<int>&nums, int target)
 {
     int l = 0, r = nums.size() - 1, mid = l + (r - l) / 2;
     while (l <= r)
     {
         if (nums[mid] > target)
             r = mid - 1;
         else
             l = mid + 1;
         mid = l + (r - l) / 2;
     }
     return (nums[r] == target) ? r : -1;
 }



*/
//二分查找，有重复，找左界,
//>=target(isBadVersion)的合并 r=mid-1 ,
//<target l =mid+1
class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n,mid=l+(r-l)/2;
        while(l<=r)
        {
            if(isBadVersion(mid))//isBadVersion(mid)-返回true，表明>=target(target是isbadVersion的左边界),
                r = mid-1;
            else
                l = mid+1;
            mid=l+(r-l)/2;
        }
        return l;
    }
};
