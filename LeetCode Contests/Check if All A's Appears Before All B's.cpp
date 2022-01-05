// https://leetcode.com/contest/weekly-contest-274/problems/check-if-all-as-appears-before-all-bs/

//////////////////////////////// Brute  //////////////////////////
class Solution {
public:
    bool checkString(string s) {
        int A=-1,B=-1;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i] == 'a'){
                A = i;
            }
            else if(s[i] == 'b'){
               if(B == -1){
                   B = i;
               }
            }
        }
        if(A < B  || A == -1 || B == -1){
            return true;
        }
        return false;
    }
};

///////////////////////////// Optimal /////////////////////////
bool checkString(string s) {
        return is_sorted(s.begin(),s.end());
    }
