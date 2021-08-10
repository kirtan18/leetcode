https://leetcode.com/contest/weekly-contest-253/problems/check-if-string-is-a-prefix-of-array/


/////////////////////////////////////////////////////////////////////////////////////////////////////
T.C = O(N^2) S.C = O(1)
  
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        
        string ans = "";
        
        for(auto str : words){
            for(auto it : str){
                ans += it;
            }
            
            if(ans == s){
                return true;
            }
        }
        return false;
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////////////
T.C = O(N) 
S.C = O(1)
  
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string res = "";
        for (auto w : words) {
            res += w;
            if (res == s) return true;
        }
        return false;
    }
};  
