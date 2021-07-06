// https://leetcode.com/problems/sqrtx/

 
///////////////////////////////////////////// TLE  ///////////////////////////////////////

 class Solution {
public:
    int mySqrt(int x) {
        
     double root = 1;
     int i = 0;
     
    while (1)
    {
        i = i + 1;
        root = (x / root + root) / 2;
        if (i == x + 1) { break; }
    }
        return int(root);
    }
};

/////////////////////////////////////  Optimal using newton's them //////////////////////////

class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        
        while( r*r > x)
            r = (r + x/r) / 2;     
        return r;
    }
};



////////////////////////////////  Optimal using Binary Search  T.C = O(logn) || S.C = O(1)  ///////////////////////////////////

class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int h = x;
        int m;
        
        while(l <= h){
            m = l + (h - l) / 2;
            if( m == x/m){ //for avoid exceed m*m = x so 
                return m;
            }
            else if(m > x/m){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return l-1;
    }
};






