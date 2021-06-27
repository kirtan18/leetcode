// https://leetcode.com/problems/word-break/


////////////////////////////////////////////////////////  Recursive(TLE)  ///////////////////////////////////////////////////// //


class Solution {
public:
    
    bool helper(int i, string s, set<string>& wordDict){
        if(i == s.size())return 1;
        string temp;
        
        for(int j = i ; j < s.size() ; j++){
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()){
                 if(helper(j+1 ,s , wordDict))return 1;
            }
        }
        return 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string>st;
       for(auto it : wordDict)st.insert(it); 
       return helper(0,s,st);
    }
};


////////////////////////////////////////////////////  Top-Down ////////////////////////////////////////////////////
//////////////////////////////////////////////////  Time : O(N) , Space : O(n) ////////////////////////////////////

class Solution {
public:
    int dp[301];
    bool helper(int i, string s, set<string>& wordDict){
        if(i == s.size())return 1;
        string temp;
        if(dp[i] != -1)return dp[i];
        for(int j = i ; j < s.size() ; j++){
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()){
                 if(helper(j+1 ,s , wordDict))return dp[i] = 1;
            }
        }
        return dp[i]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
       set<string>st;
       for(auto it : wordDict)st.insert(it); 
       return helper(0,s,st);
    }
};


