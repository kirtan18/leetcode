// https://leetcode.com/contest/weekly-contest-276/problems/solving-questions-with-brainpower/

class Solution {
    public:
          #define ll long long
          ll dp[200001] = {{0}};
          ll solve(int ind ,vector<vector<int>>& que , int n){
              if(dp[ind] != 0)return dp[ind];
              
              if(ind == n-1){
                  return que[ind][0];
              }
              
              if(ind >= n)return 0;
              
              ll select = que[ind][0] + solve(ind+que[ind][1]+1, que,n);
              ll ignore = 0 + solve(ind+1,que,n);
              return dp[ind] =  max(select,ignore);
          }
public:
    long long mostPoints(vector<vector<int>>& que) {
        int n = que.size();
        return solve(0,que,n);
    }
};
