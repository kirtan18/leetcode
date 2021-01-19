class Solution {
public:
    
    string reverseWords(string s) {
        int n = s.size();
        
        stack<string> st;
        string ans;
        
        for(int i = 0 ; i < n ; i ++){
            string word;
            
            if(s[i] == ' ') continue;
            
            while(i<n && s[i] != ' ' ){
                word += s[i];
                i++;
            }
            st.push(word);
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty())   ans += " ";
        }
        
        return ans;
    }
    
    /*
    
    // time == O(n)  space = O(n)
    string reverseWords(string s) {
       stringstream ss(s);
        string word;
        vector<string>v;
        
        while(ss>>word)
            v.push_back(word);
        
        string ans = "";
        for(int i = v.size()-1 ; i>=0 ;i--){
            ans += v[i] + ' ';
        }
        ans.erase(ans.end()-1);
        return ans;
    }
    */
};
​
​
​
​
