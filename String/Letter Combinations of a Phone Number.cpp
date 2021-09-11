https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    
    void dfs(string digits ,vector<string>& ans,string nums[],int i, string s){
        
        if(i == digits.length()){
            ans.push_back(s);
            return;
        }
        string val = nums[digits[i] - '0'];
        
        for(int j=0;j<val.length(); j++)
            dfs(digits, ans, nums, i+1, s+val[j]);
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length() == 0) return ans;
        
        string nums[10] ={
          "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"  
        };
        dfs(digits,ans,nums,0,"");
        return ans;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
    
    vector<string>rec(string &D , int i , map<int,string>&mp){
        
        if(i == D.size()){
            return {""};
        }
        vector<string>temp = rec(D,i+1,mp);
        vector<string>ans;
        
        for(auto a : mp[D[i]-'0']){
            for(auto x : temp){
                ans.push_back(a+x);
            }
        }
        return ans;
    }
    
public:
    vector<string> letterCombinations(string D) {
        if(D.size() == 0)return {};
        map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        return rec(D,0,mp);
    }
};
