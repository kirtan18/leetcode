// https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        string ans = "";
        
        if(s.size() == 1){
            ans += s[0];
            return ans;
        }
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(mp[s[i]] > (s.size()+1)/2){
                return "";
            }
        }
        
        priority_queue<pair<int,char>>pq;
        
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
    
        while(pq.size() > 1){
            
            pair<int,char>top1 = pq.top();
            pq.pop();
            pair<int,char>top2 = pq.top();
            pq.pop();
            
            ans += top1.second;
            ans += top2.second;
            top1.first = top1.first-1;
            top2.first = top2.first-1;
            
            if(top1.first > 0){
               pq.push(top1); 
            }
            if(top2.first > 0){
                pq.push(top2);
            }
        }
      
        
        if(!pq.empty()){
            if(pq.top().first > 1){
                return "";
            }
            else{
                ans += pq.top().second;
                pq.pop();
            }
        }
        return ans;
        
    }
};
