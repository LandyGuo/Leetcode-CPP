/*
341. Flatten Nested List Iterator  
Difficulty: Medium
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/
/*
思路：
将列表展开实际上dfs的过程，先用dfs将列表里面的内容用一个vector存起来，然后每次从vector最开始取一个元素；
其思路类似于bst的iterator
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> vec;
    int index;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        index = 0;
    }
    
    
    void dfs(vector<NestedInteger> &nestedList)
    {
        for(auto l:nestedList)
        {
            if(l.isInteger())
                vec.push_back(l.getInteger());
            else
                dfs(l.getList());
        }
    }
    

    int next() {
        int res = vec[index];
        index++;
        return res;
    }

    bool hasNext() {
        return index==vec.size()?false:true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
