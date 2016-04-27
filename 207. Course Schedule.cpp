/*
207. Course Schedule   
Difficulty: Medium
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
*/
//2nd pass
/*思路：
1)dependent存储节点之间的依赖关系，out_degree存储节点的出度，is_selected存储当前课程是否已经被选择过了
2)每次遍历所有课程，找出度为0的节点(该节点没有依赖关系)而且该节点没有被选择，如果不能找到，说明课程没有办法修完；
如果能找到，则选择这门课程，然后将所有依赖该课程的出度数减去1；继续下一次选择，直到所有的课程都选择完了为止
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int,vector<int>> dependent;//int:curNode vector<int>:nodes depends on curNode
        vector<int> out_degree(numCourses,0);
        vector<int> is_selected(numCourses,0);
        for(pair<int,int> cur_pair:prerequisites)
        {
            out_degree[cur_pair.first]++;
            dependent[cur_pair.second].push_back(cur_pair.first);
        }
        int finished_class = 0;
        while(finished_class<numCourses)
        {
            int cur_choice = -1;
            for(int i=0;i<out_degree.size();i++)
            {
                if(out_degree[i]==0&&is_selected[i]==0)//choose i
                {
                     cur_choice = i;
                     is_selected[i]=1;
                     break;
                }
            }
            if(cur_choice==-1)//no choice
                return false;
            finished_class++;
            //has choice
            for(int x:dependent[cur_choice])//当前课已经选择了，所有依赖此节点的度减去1
                out_degree[x]--;
        }
        return true;
    }
};
