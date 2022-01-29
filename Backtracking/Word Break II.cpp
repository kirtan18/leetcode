// https://leetcode.com/problems/word-break-ii/

class Solution {
    unordered_map<string,vector<string>>dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s) != dp.end()) return dp[s];
        vector<string>ans;       
        for(auto w : wordDict){
            if(s.substr(0,w.size()) == w){
                if(w.size() == s.size()){
                    ans.push_back(w);
                }
                else{
                    vector<string>temp = wordBreak(s.substr(w.size()),wordDict);
                    for(string t : temp){
                        ans.push_back(w + " " + t);
                    }
                }
            }
        }
        dp[s] = ans;
        return ans;
    }
};

///////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<stirng>ans;       
        for(auto w : wordDict){
            if(s.substr(0,w.size()) == w){
                if(w.size() == s.size()){
                    ans.push_back(w);
                }
                else{
                    vector<string>temp = wordBreak(s.substr(w.size()),wordDict);
                    for(string t : temp){
                        ans.push_back(w + " " + t);
                    }
                }
            }
        }
        return ans;
    }
};
