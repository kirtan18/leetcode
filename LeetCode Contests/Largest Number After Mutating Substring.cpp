https://leetcode.com/contest/weekly-contest-251/problems/largest-number-after-mutating-substring/


class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
      
        int n = num.size();
        int flag = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            int d = num[i] - '0';
            
            if(d > change[d]){
                if(flag){
                    break;
                }
            }
            else if(d < change[d]){
                flag = 1;
                num[i] = '0' + change[d];
            }
            
            
        }
        return num;
        
    }
};
