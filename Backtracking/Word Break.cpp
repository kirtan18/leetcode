// https://leetcode.com/problems/word-break/

class Solution {
    int dp[301];
    
    bool solve(int i,string s,set<string>& st){
        if(i == s.size()){
            return dp[i] = 1;
        }
        string temp;
        if(dp[i] != -1)return dp[i];
        for(int j=i;j<s.size();j++){
            temp += s[j];
            
            if(st.find(temp) != st.end()){
                if(solve(j+1,s,st)){
                  return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        set<string>st;
        for(auto it : wordDict)st.insert(it);
        return solve(0,s,st);
    }
};
