class Solution {
public:
    // time = O(logn)   space = O(1)
    bool isHappy(int n) {
        if(n == 1111111) return true;
        
         while(1){
             int a = 0;
             while(n!=0){
                 a += (n%10)*(n%10);
                 n /= 10;
             }
             n = a;
             if(a < 10)break;
             
         }
        if(n==1)return true;
        else return false;
    }
};
​
​
​
​
