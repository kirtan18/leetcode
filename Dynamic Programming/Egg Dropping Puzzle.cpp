https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#

/////////////////////////////////////  Recursion || TLE /////////////////////////////////////


class Solution
{
    public:
    int eggDrop(int n, int k) 
    {
        if(k == 0 || k == 1)return k;
        if(n == 1)return k;
        
        int mn = INT_MAX ,temp;
        
        for(int i = 1 ; i <= k ; i++){
            
           temp = 1 +  max(eggDrop(n-1,k-1) , eggDrop(n,k-n));
            
            if(temp < mn){
                mn = temp;
            }           
        }
        return mn;
    }
};


////////////////////////////////  Optimal || Bottom UP || T.C = O(N*K) || S.C = O(N)  //////////////////////////////////////

#define MAX 1000
vector<vector<int>> dp(MAX, vector<int> (MAX, -1));
class Solution
{
    public:
   
    int eggDrop(int n, int k) 
    {
        if (k == 1 || k == 0)
            return k;

        if (n == 1)
          return k;
          
        if(dp[n][k] != -1){
            return dp[n][k];
        }  
 
        int min = INT_MAX, x, res;

    for (x = 1; x <= k; x++) {
        res = 1 +  max(
            eggDrop(n - 1, x - 1),
            eggDrop(n, k - x));
        if (res < min)
            min = res;
    }
 
    return  dp[n][k] = min;
    }
};



