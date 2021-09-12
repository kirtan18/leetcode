https://leetcode.com/problems/decode-string/



class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                
                string curr = "";
                
                // got all the stirng in bracket
                while(st.top() != '['){
                    curr = st.top() + curr;
                    st.pop();
                }
                st.pop();
                
                string number = "";
                
                // got the number for how many types we can write strings
                while(!st.empty() && isdigit(st.top())){
                    number = st.top()+number;
                    st.pop();
                }
                
                int k_time = stoi(number);
                
                while(k_time--){
                    for(int p = 0 ;  p < curr.size() ; p++){
                        st.push(curr[p]);
                    }
                }
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

