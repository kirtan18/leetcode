https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3887/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        
        for(auto i : strs){
            string temp = i;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        
        vector<vector<string>>ans;
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
