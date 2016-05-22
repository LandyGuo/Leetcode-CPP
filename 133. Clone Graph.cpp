/*
133. Clone Graph 
Difficulty: Medium
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 //2nd pass
 /*
 思路：
 1.bfs遍历这个图
 2.遍历到某个节点时，
 对这个节点做以下处理：如果没复制则复制这个节点，复制这个节点的所有没有复制的邻居节点，并增加到这个节点的邻居里面
 对所有已经经过以上处理的节点进行登记(为了避免出现环和循环复制),已经登记的直接跳过上述处理
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return node;
        //bfs广度遍历这个无向图
        queue<UndirectedGraphNode*> q;
        q.push(node);
        //复制头节点
        int start_node = node->label;
        unordered_map<int,UndirectedGraphNode*> clonedNodes;
        set<UndirectedGraphNode*> visited;
        while(!q.empty())
        {
            UndirectedGraphNode * cur = q.front();
            q.pop();
            if(visited.find(cur)!=visited.end()) continue;
            if(clonedNodes.find(cur->label)==clonedNodes.end())
                clonedNodes[cur->label] = new UndirectedGraphNode(cur->label);
            UndirectedGraphNode * cloneCur = clonedNodes[cur->label];//取当前节点的复制
            //对当前节点的neighbors进行复制
            for(UndirectedGraphNode* neighbor:cur->neighbors)
            {
                if(clonedNodes.find(neighbor->label)==clonedNodes.end())
                    clonedNodes[neighbor->label] = new UndirectedGraphNode(neighbor->label);
                cloneCur->neighbors.push_back(clonedNodes[neighbor->label]);//取当前节点的复制
                q.push(neighbor);
            }
            visited.insert(cur);
        }
        return clonedNodes[start_node];
    }
};
