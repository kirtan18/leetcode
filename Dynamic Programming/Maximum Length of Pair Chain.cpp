https://leetcode.com/problems/maximum-length-of-pair-chain/

//////////////////////// Brute || T.C = O(N^2) ////////////////////////////

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n+1,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};

////////////////////// Optimal || T.C = O(NlogN) //////////////////////////////


class Solution {
      static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
         
        sort(pairs.begin(),pairs.end(),cmp);
        
        int i=0;
        int j=1;
        int cnt = 1;
        
        while(j < n){
            if(pairs[i][1] < pairs[j][0]){
                i = j;
                j++;
                cnt++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};
