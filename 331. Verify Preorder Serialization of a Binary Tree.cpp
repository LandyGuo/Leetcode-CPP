/*
331. Verify Preorder Serialization of a Binary Tree   
Difficulty: Medium
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/
//2nd pass
/*
思路：根据二叉树上还能挂几个节点，一个根节点(如果不为"#")后面还有2个空位置，
增加一个子节点，如果是数，可以增加一个空位置；如果是"#"减少一个空位置
如果序列没遍历完，就始终保持empty_space>=0 并且empty_space最后一定是0
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return true;
        preorder+=',';
        queue<string> pre_string;
        int start=0,end = preorder.find_first_of(',');
        while(end!=string::npos)
        {
            string cur = preorder.substr(start,end-start);
            pre_string.push(cur);
            start = end+1;
            end = preorder.find_first_of(',',start);//注意：find_first_of(char,offset)
        }
        int out_degree = pre_string.front()=="#"?0:2;
        pre_string.pop();
        while(!pre_string.empty())
        {
            if(out_degree<=0)//每当一个"#"出度减少1，如果一个节点，出度加上1
                return false;
            string cur = pre_string.front();
            pre_string.pop();
            if(cur=="#")
                out_degree-=1;
            else
                out_degree+=1;
        }
        return out_degree==0;//最终树的出度一定为0
    }
};
