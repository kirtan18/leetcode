https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

class Solution {
public: 
    // time  == O(n)  space == O(1)
    
    int concatenatedBinary(int n) {
        long long int val = 0;
        int i=1;
        
        while(i <= n){
            val = ((val << (1 + int(log2(i)))) % 1000000007 + i) % 1000000007 ;
            i += 1;
        }
        return val;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    const int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        return (n == 1) ? 1 : (concatenatedBinary(n - 1) * (long)(pow(2, 1 + (int)log2(n))) + n) % mod;
    }
}; 
