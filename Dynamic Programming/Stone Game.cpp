https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3870/




class Solution {
    int dp[501][501];
    int helper(int i , int j , vector<int>&p){
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = max(p[i] - helper(i+1,j,p) , p[j] - helper(i,j-1,p));
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof dp);
        return helper(0,n-1,piles) > 0;
    }
};
