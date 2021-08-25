https://leetcode.com/problems/sum-of-square-numbers/

//////////////////////////////////////// Brute Force || T.C = TLE || S.C = O(1) //////////////////////////////////////

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a  = 0 ; a*a <= c ; a++){
            for(long b = 0 ; b*b <= c ; b++){
                if((a*a + b*b) == c){
                    return true;
                }
            }
        }
        return false;
    }
};

/////////////////////////////////////// T.C = O(root(c)LogC) || S.C = O(1) ////////////////////////////////////////////

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0 ; a*a <= c ; a++){
            double b = sqrt(c-a*a);
            if(b == (int)b){
                return true;
            }
          }
        return false;
     }
};

///////////////////////////////////////TLE  ||  T.C = O(root(c)LogC) || S.C = O(1) || binary search ////////////////////////////////////////////

class Solution {
    bool binary_search(long s,long e,long n){
        if(s>e){
            return false;
        }
        long mid = s + (e-s) / 2;
        if(mid*mid == n){
            return true;
        }
        if(mid * mid > n){
            return binary_search(s,mid-1,n);
        }
        return binary_search(mid-1,e,n);
    }
public:
    bool judgeSquareSum(int c) {
        for(long a = 0 ; a*a <= c ; a++){
            int b = c - (int)(a*a);
            if(binary_search(0,b,b)){
                return true;
            }
        }
        return false;
     }
};

