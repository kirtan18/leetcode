https://leetcode.com/problems/generate-parentheses/


class Solution {
    
    void solve(int open ,int close,int n,string s , vector<string>&res){
        if(s.size() == n*2){
            res.push_back(s);
            return;
        }
        
        if(open<n) solve(open+1,close,n,s+"(",res);
        if(close<open) solve(open,close+1,n,s+")",res);
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(0,0,n,"",res);
        return res;
    }
};
