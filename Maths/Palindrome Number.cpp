https://leetcode.com/problems/palindrome-number/

//////////////////////////////////////////////  T.C = O(logn)  || S.C = O(1)   ///////////////////////////////////////

class Solution {
public:
    bool isPalindrome(int x) {
      
        int y = 0;
        int ans = x;
       
        if(x < 0)return false;        
        while(x != 0){
             // if Overflow or not
            if(y > INT_MAX/10 || y < INT_MIN/10){
                return false;
            }
            y = y * 10 + x % 10;
            x /= 10;
        }        
      
        if( ans == y )return true;
        else return false;  
    }
};
