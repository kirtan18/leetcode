#include<bits/stdc++.h>
               // n * 26 * n * w
               // time = O(n2 * w)       
​
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>myset;
        bool ispresent = false; // Checks if endWord is present in Dict
        
        // insert all words in set
        for(auto word : wordList){
          if(endWord.compare(word)==0)
                ispresent = true;
            myset.insert(word);    //Insert word in Dict
        }
        if(ispresent == false)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty()){
            depth += 1;
            int lsize = q.size();
            
            while(lsize--){
                string curr = q.front();
                q.pop();
                //check for all possible 1 depth words
                
                for(int i=0;i<curr.length();++i){    //For each index
                    string temp = curr;
                    
