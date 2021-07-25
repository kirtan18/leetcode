https://leetcode.com/contest/weekly-contest-251/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
    int getLucky(string s, int k) {
        
       int NUM = 31;
        vector<int>v;
        int stor = 0 ;
        string curr =  "";
        for(int i = 0 ; i < s.size() ; i++){
           // to convert char index means if a then 1 and z then 26 and d = 4 , e = 5 thats it // it's convert into sbcd wise index number           
           curr += to_string(s[i] & NUM);

        }
        int temp1 = 0;
        for(int i = 0 ; i < curr.size() ; i++){
            temp1 += curr[i] - '0';
        }
        cout << temp1;
        
        k--;
        
        if(k == 0){
            return temp1;
        }
        else{
    
            string ans= to_string(temp1);  
            while(k != 0){
              
                for(int i = 0 ; i < ans.size() ; i++){
                    stor += ans[i] - '0';
                }
                k--;
                if(k != 0){
                    ans = to_string(stor);
                    stor = 0;
                }
            }
        }
        
       return stor;
    }
};
