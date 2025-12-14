/*
Problem credits: https://leetcode.com/problems/implement-queue-using-stacks/

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Solution: Making pop to be O(n).
*/
class MyQueue {
public:
    stack<int> input, output;    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int x = peek();
        output.pop();
        return x;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */