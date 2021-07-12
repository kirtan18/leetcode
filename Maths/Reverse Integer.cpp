https://leetcode.com/problems/reverse-integer/

////////////////////////////////////////////  Brute Force || TLE  || S.C = O(1)  //////////////////////////////

class Solution {
public:
    int reverse(int x) {
        
        int temp = 0 ;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            temp = temp * 10 + pop ;
        }
        return temp;
        
    }
};


/////////////////////////////////////  Optimal  || T.C = O() || S.C = O(1) ////////////////////////////////////

class Solution {
public:
    int reverse(int x) {
        
        int y = 0 ;
        while(x != 0){
           if(y > INT_MAX/10 || y < INT_MIN/10){
               return 0;
           }else{
               y = y * 10 + x % 10;
               x /= 10;
           }
        }
        return y; 
    }
};
 
