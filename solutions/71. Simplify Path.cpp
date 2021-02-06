                        if (!st.empty()) {
                            st.pop();
                        }
                    }
                    else {
                        // append the cur dir
                        st.push(cur);
                    }
                }
                cur.clear();
                i += 1;
            }
            else {
                cur += path[i];
                i += 1;
            }
        }
        // construct result string from stack
        string rst = "";
        while (!st.empty()) {
            rst = "/" + st.top() + rst;
            st.pop();
        }
        if (rst.empty()) rst += '/';
        return rst;
    }
};
​
​
/*
class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        stack<string>s;
                
        if(path[n-1]!='/') // so that initially path always ends with '/'
            path+="/", ++n;
            
        int i=1; // since path always starts from '/'
        string ans="";
        string temp="";
        while(i<n){
            
            if(path[i]=='/'){ // check only if we encounter '/'
                
                if(temp=="" || temp=="."){
                    // ignore
                }
                else if(temp==".."){
                    if(!s.empty()) s.pop(); // pop the top element from stack if exists
                }
                else{
                    s.push(temp); //push the directory or file name to stack
                }
