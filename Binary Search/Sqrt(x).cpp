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
