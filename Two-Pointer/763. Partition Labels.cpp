https://leetcode.com/problems/partition-labels/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;
        int first = 0 , last = 0;
        int n = s.size();
        
        for(int i = 0 ; i < n ; i++){
            mp[s[i]] = i;
        }
        first = mp[s[0]];
        if(first == 0){
            ans.push_back(1);
            first = mp[s[1]];
            last = 1;
        }
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(mp[s[i]] > first){
                first = mp[s[i]];
            }
            else if(first == i){
                cout << first;
                if(last == 0){
                    ans.push_back(i+1);
                    last = i+1;
                    first = mp[s[i+1]]; 
                }
                else{
                    ans.push_back(i+1 - last);
                    last = i+1;
                    first = mp[s[i+1]];  
                }
            }
        }
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////////////////
 vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        int i=0;
        vector<int> ans;
        int visited=0;
        while(i<s.length()){
            int curLimit=m[s[i]];
            while(i<=curLimit){
                curLimit=max(curLimit, m[s[i]]);
                i++;
            }            
            ans.push_back(i-visited);
            visited=i;
        }
        return ans;
    }

