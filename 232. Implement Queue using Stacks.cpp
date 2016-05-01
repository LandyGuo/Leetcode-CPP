/*
232. Implement Queue using Stacks  
Difficulty: Easy
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

/*2nd pass
思路：
用两个栈，一个专门负责进元素，一个专门负责出元素
1)push : 直接进stack_in
2)pop|peak: 如果stack_out不为空，直接出，每当stack_out为空，就从stack_in中倒腾过来所有元素，然后再出一个（peak:不出，只返回）
3)empty: 当stack_in 和 stack_out 都为空时，此时栈为空
*/
class Queue {
private:
    stack<int>s_in,s_out;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s_in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s_out.empty())
        {
            while(!s_in.empty())
            {
                int cur = s_in.top();
                s_in.pop();
                s_out.push(cur);
            }
        }
        s_out.pop();
    }

    // Get the front element.
    int peek(void) {
        if(s_out.empty())
        {
            while(!s_in.empty())
            {
                int cur = s_in.top();
                s_in.pop();
                s_out.push(cur);
            }
        }
        return s_out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s_in.empty()&&s_out.empty();
    }
};
