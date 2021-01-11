#include<stack>
class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {     
     s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        while(!s1.empty()){
         s2.push(s1.top());
         s1.pop();
       }    
        
       int k = s2.top();
       s2.pop();
       
       while(!s2.empty()){
           s1.push(s2.top());
           s2.pop();
       } 
       return k; 
    }
    
    /** Get the front element. */
    int peek() {
