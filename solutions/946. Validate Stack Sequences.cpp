class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int i=0;
        for (int j=0;j<pushed.size();++j) {
            s.push(pushed[j]);
            
            // check weather the current top element of stack matches with the "i"th element that needs to get popped
            while (!s.empty() && s.top() == popped[i]) s.pop(), ++i;
        }
        
        // Since pushed is a permutation of popped at the end we are supposed to be left with an empty stack
        return s.empty();
    }
};
​
/*class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k=-1; // for using the "pushed" vector as "stack"
        int i=0;
        for (int j=0;j<pushed.size();++j) {
            pushed[++k] = pushed[j];
            
            // check weather the current top element of stack matches with the "i"th element that needs to get popped
            while (k!=-1 && pushed[k] == popped[i]) --k, ++i;
        }
        
        // Since pushed is a permutation of popped so at the end we are supposed to be left with an empty stack
        return k==-1;
    }
}; */
