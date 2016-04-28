/*
297. Serialize and Deserialize Binary Tree  
Difficulty: Hard
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //2nd pass
 /*
 思路：
 用层序遍历的结果进行序列化，序列化时和反序列化时都需要用层序遍历的队列作为辅助
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		vector<int> res;
		if(root==NULL)
		    return "";
		queue<TreeNode*>q;
		q.push(root);
		res.push_back(root->val);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			if (cur != NULL)//层序遍历，用INT_MAX代替None节点，方便序列化
			{
				if (cur->left == NULL)
					res.push_back(INT_MAX);
				else
				{
					res.push_back(cur->left->val);
					q.push(cur->left);
				}

				if (cur->right == NULL)
					res.push_back(INT_MAX);
				else
				{
					res.push_back(cur->right->val);
					q.push(cur->right);
				}
			}
		}
		//把res序列化
		string ret;
		for (int i = 0; i<res.size(); i++)
		{
			char buf[32];
			sprintf(buf, "%d", res[i]);
			ret = ret + string(buf) + ',';
		}
		return ret;

	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty())
			return NULL;
		//先把data反序列化
		deque<int>nodes;
		size_t start = 0;
		size_t end = data.find_first_of(',');
		while (end != string::npos)
		{
			string cur_node_val = data.substr(start, end - start);//将cur_val转换为int
			nodes.push_back(atoi(cur_node_val.c_str()));
			start = end + 1;
			end = data.find_first_of(',', start);
		}
		//重建树
		TreeNode* root = new TreeNode(nodes.front());
		nodes.pop_front();
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			if (cur != NULL)
			{
				int l_val = INT_MAX, r_val = INT_MAX;
				if (!nodes.empty())
				{
					l_val = nodes.front();
					nodes.pop_front();
				}
				if (!nodes.empty())
				{
					r_val = nodes.front();
					nodes.pop_front();
				}
				cur->left = (l_val == INT_MAX) ? NULL : new TreeNode(l_val);
				cur->right = (r_val == INT_MAX) ? NULL : new TreeNode(r_val);
				if (cur->left != NULL)
					q.push(cur->left);
				if (cur->right != NULL)
					q.push(cur->right);
			}
		}
		return root;
	}
};
