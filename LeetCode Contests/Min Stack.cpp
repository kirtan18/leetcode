https://leetcode.com/problems/min-stack/


////////////////////////////////// Using Two Stack  /////////////////////////////
class MinStack {
    stack<int>s1,s2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s2.empty() || val <= s2.top())s2.push(val);
        s1.push(val);
    }
    
    void pop() {
        if(s1.top() == s2.top())s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};


/////////////////////////////// Using One Stack ///////////////////////////////////

class MinStack {
public:
    vector<pair<int,int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push_back({val,val});
        }
        else{
            s.push_back({val,min(s.back().second,val)});
        }
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};
