https://leetcode.com/contest/biweekly-contest-57/problems/check-if-all-characters-have-equal-number-of-occurrences/


 bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        vector<char>v; 
       
        for(int i = 0 ; i < s.size() ; i++){
            
            if(mp.find(s[i]) == mp.end()){
                v.push_back(s[i]);
            }
            mp[s[i]]++;
        }
    
        for(int i = 0 ; i < v.size()-1 ; i++){
            if(mp[v[i]] != mp[v[i+1]]){
                return false;
            }
        }
        
        return true;
    }
