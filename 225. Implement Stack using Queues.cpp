/*
225. Implement Stack using Queues  
Difficulty: Easy
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.
*/
/*
思路：用两个队列，其中一个缓存已经进来的元素，另一个始终为空(两个队列始终有一个为空)
push:新加入元素只往为空的队列1加，加完后把另一个刚开始不为空的队列2所有元素全部移到队列1后面，这时队列2为空
pop|top:不为空的队列第一个元素
empty:两个队列都为空时
*/
class Stack {
private:
        queue<int> que1,que2;
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int>* full_que,*empty_que;
        if(que1.empty())
            full_que = &que2,empty_que = &que1;
        else
            full_que = &que1,empty_que = &que2;
        empty_que->push(x);
        while(!full_que->empty())
        {
            int cur = full_que->front();
            empty_que->push(cur);
            full_que->pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!que1.empty())
            que1.pop();
        else
            que2.pop();
    }

    // Get the top element.
    int top() {
        return !que1.empty()?que1.front():que2.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que1.empty()&&que2.empty();
    }
};
