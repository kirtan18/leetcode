// https://leetcode.com/problems/construct-string-with-repeat-limit/


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};
        string ans = "";
        for(auto c : s){
            freq[c-'a']++;
        }
        
        priority_queue<pair<char,int>>pq;
        
        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                pq.emplace((i+'a'),freq[i]);
            }
        }
        
        while(!pq.empty()){
            
            auto [key,val] = pq.top();
            pq.pop();
            int count = val;
            
            for(int i=0;i<repeatLimit && count > 0 ; i++){
                ans += key;
                count--;
            }
            
            if(count > 0 && pq.size() > 0){
                auto [secondKey , secondVal] = pq.top();
                pq.pop();
                
                ans += secondKey;
                if(secondVal > 1){
                    pq.emplace(secondKey,secondVal-1);
                }
                
                pq.emplace(key,count);
            }      
        }
        
        return ans;
    }
};
