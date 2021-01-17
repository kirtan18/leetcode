class Solution {
public:
    // math solution
    // space = O(1)
        int countVowelStrings(int n) {
              return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
        }
};
​
 
    /*
    // time  = O(n) space = O(1)
    int countVowelStrings(int n) {
        int a = 1;
        int e = 1;
        int i = 1;
        int o = 1;
        int u = 1;
        
        while(--n){
            e += a;
            i += e;
            o += i;
            u += o;
        }
       
       return a+e+i+o+u; 
    }
};*/
