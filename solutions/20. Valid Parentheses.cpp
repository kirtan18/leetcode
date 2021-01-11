#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char>ans;
        char x;
        
        for(int i =0;i<s.length() ; i++){
            
             if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                 ans.push(s[i]);
                 continue;
             }
            
            if(ans.empty()){
                return false;
            }
            
            switch(s[i]){
                    
                case ')':
                    x = ans.top();
                    ans.pop();
                    
                    if(x == '{' || x == '['){
                        return false;
                    }
                    break;
                    
                case '}':
                    x = ans.top();
                    ans.pop();
                    
                    if(x == '(' || x == '['){
                        return false;
