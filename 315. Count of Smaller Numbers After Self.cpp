/*
315. Count of Smaller Numbers After Self 
Difficulty: Hard
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/
/*
思路：
    1）用二叉排序树进行计数，每个BST节点记录以当前节点为根节点的子树上<当前节点的有多少个，=当前节点的有多少个；这样就有点儿类似于以二叉排序树的根节点对其进行分段统计
    2）将输入的节点逆序插入BST，当插入节点的同时对<=当前节点的进行计数
举例：9 5 2 6 4
1)插入4
        4(lt_cnt=0,equal_cnt=1)
---------------------------------
        ret = 0
        
2)插入6
        4(lt_cnt=0,equal_cnt=1)
            \
            6(lt_cnt=0,equal_cnt=1)
----------------------------------------
        ret = 4(equal_cnt=1)+4(lt_cnt=0) =1
        
3)插入2
                              4(lt_cnt=1,equal_cnt=1)
                            /                       \
         2(lt_cnt=0,equal_cnt=1)                        6(lt_cnt=0,equal_cnt=1)
--------------------------------------------------------------------------------
        ret = 0
4)插入5
                              4(lt_cnt=1,equal_cnt=1)
                            /                       \
         2(lt_cnt=0,equal_cnt=1)                    6(lt_cnt=1,equal_cnt=1)   
                                                      /
                                        5(lt_cnt=0,equal_cnt=1)
--------------------------------------------------------------------------------
        ret = 4(lt_cnt=1,equal_cnt=1) = 2               （从根节点往右走才计算）
        
5)插入9
                              4(lt_cnt=1,equal_cnt=1)
                            /                       \
         2(lt_cnt=0,equal_cnt=1)                    6(lt_cnt=1,equal_cnt=1)   
                                                      /                    \
                                        5(lt_cnt=0,equal_cnt=1)        9(lt_cnt=0,equal_cnt=1)

---------------------------------------------------------------------------------
      ret = 4(lt_cnt=1,equal_cnt=1) + 6(lt_cnt=1,equal_cnt=1)  =4             （从根节点往右走才计算）


*/


struct Node
{
	int val;
    Node *left,*right;
	int lt_cnt;
	int equal_cnt;
    Node(int val)
	{
		this->val = val;
		left = right = NULL;
		lt_cnt = 0;
		equal_cnt = 1;
	}
};

class BST
{
public:
    Node * root;
	BST()
	{
		root = NULL;
	}

	int addNode(int val)
	{
		if (!root)
		{
			root = new  Node(val);
			return 0;
		}
	    Node* curNode = root;
		int cnt = 0;
		while (curNode)
		{
			if (val > curNode->val)//greater than
			{
				cnt += (curNode->equal_cnt + curNode->lt_cnt);//注意1：只有往右走才计算小于等于的值
				if (curNode->right == NULL)
				{
					curNode->right = new    Node(val);//注意:new一个节点时，小于新节点的节点数肯定为0，因此不用累计
					break;
				}
				curNode = curNode->right;
			}
			else if (val < curNode->val)//less than
			{
				curNode->lt_cnt += 1;
				if (curNode->left == NULL)
				{
					curNode->left = new Node(val);
					break;
				}
				curNode = curNode->left;
			}
			else//equal
			{
				cnt += curNode->lt_cnt;//注意2：加上小于当前节点值的节点数
				curNode->equal_cnt += 1;
				break;
			}
		}
		return cnt;
	}
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>res(nums.size(),0);
        int i = nums.size()-1;
        BST bst = BST();
        for(auto p = nums.rbegin();p!=nums.rend();p++)//注意倒序插入
        {
            res[i--] = bst.addNode(*p);
        }
        return res;
    }
};

