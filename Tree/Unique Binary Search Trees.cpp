https://leetcode.com/problems/unique-binary-search-trees/


/////////////////////////////////////////// Using DP || T.C = O(N) || S.C = O(1)  //////////////////////////////////

class Solution {
public:
    int numTrees(int n) {
        int catlan[n+1];
        catlan[0] = catlan[1] = 1;
        
        for(int i = 2 ; i <= n ; i++){
            catlan[i] = 0;
            for(int j = 0 ; j < i ; j++){
                catlan[i]  +=  catlan[j] * catlan[i - j - 1];
            }
        }
        return catlan[n];
    }
};

//////////////////////////////////////////////  Without DP || T.C = O(N)  || S.C = O(1)  ///////////////////////////////
class Solution {
public:
    int numTrees(int n) {
        long long int a = 1;
        
        for(int i = n+1 ; i <= 2*n ;i++){
             a *= i;
            a /= (i-n);
        }
        a /= (n+1);
        return a;
    }
};
