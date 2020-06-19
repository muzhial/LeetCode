#include "../common.hpp"
using namespace std;
using std::queue;

/***************
****************/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    /** Push element x onto stack. */
    void push(int x) {
        q_.push(x);
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int sz = q_.size();
        while (sz > 1) {
            q_.push(q_.front());
            q_.pop();
            sz--;
        }
        int res = q_.front();
        q_.pop();
        return res;
    }
    /** Get the top element. */
    int top() {
        return q_.back();
    }
    /** Returns whether the stack is empty. */
    bool empty() {
        return q_.empty();
    }
private:
    queue<int> q_;
};