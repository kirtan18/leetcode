#include<queue>
class MyStack {
public:
    queue<int>que;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
     que.push(x);
     int size = que.size();
       
     while(size > 1){
         que.push(que.front());
         que.pop();
         size--;
      } 
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
       int res = que.front();
       que.pop();
       return res; 
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
