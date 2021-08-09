https://leetcode.com/contest/biweekly-contest-58/problems/delete-characters-to-make-fancy-string/

class Solution {
public:
    string makeFancyString(string s) {
     
         string ans = "";
         int cnt = 1;
        
         for(int i = 0 ; i < s.size() ; i++){  
             if(cnt == 3){
                 if(s[i] != s[i+1]){
                     cnt = 1;
                 }
                 continue;
             }
             if(s[i] != s[i+1]){
                 cnt = 1;
             }
             else{
                 cnt++;
             }
             ans += s[i];              
         }
          return ans;
    }
};
