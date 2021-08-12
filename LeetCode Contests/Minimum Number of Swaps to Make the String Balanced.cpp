https://leetcode.com/contest/weekly-contest-253/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        int close = 0;
        int maxi = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){    
            if(s[i] == ']'){
                close++;
            }
            else{
                close--;
            } 
            maxi = max(maxi,close);
        }
        return (maxi+1)/2;
    }
};
