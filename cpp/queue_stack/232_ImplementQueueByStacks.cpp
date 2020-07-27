#include "../common.hpp"
using std::stack;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        s1_.push(x);
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int res = s2_.top();
        s2_.pop();
        return res;
    }
    /** Get the front element. */
    int peek() {
        if (s2_.empty()) {
            while (!s1_.empty()) {
                s2_.push(s1_.top());
                s1_.pop();
            }
        }
        return s2_.top();
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1_.empty() && s2_.empty();
    }
private:
    // 队头        队尾
    // -----     -------
    //   s2 |   |   s1
    // -----     -------
    stack<int> s1_;
    stack<int> s2_;
};
