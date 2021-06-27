// https://leetcode.com/contest/biweekly-contest-55/problems/maximum-alternating-subsequence-sum/


//////////////////////////////////    First Approch /////////////////////////////

#define ll long long
class Solution {
public:
    ll dp[100001][2];
    
    ll help(int i , int flag , vector<int>& nums){
        if(i == nums.size())return 0;
        if(dp[i][flag] != INT_MIN)return dp[i][flag];
        ll op1 = help(i+1,flag,nums);    
        ll op2 = 0;
        if(flag == 1)op2 += nums[i];
        else op2 -= nums[i];
        op2 += help(i+1,1-flag,nums);
        return dp[i][flag] = max(op1,op2);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0 ; i < 100001 ; i++){
            dp[i][0] = INT_MIN;
            dp[i][1] = INT_MIN;
        }
        return help(0,1,nums);
    }
};


//////////////////////////////////////  Second Approch ////////////////////////////////////

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp1(n + 1);
        vector<long long> dp2(n + 1);
        for(int i = 1; i <= n; i++) {
            dp1[i] = max(dp1[i - 1], dp2[i - 1] + nums[i - 1]);
            dp2[i] = max(dp2[i - 1], dp1[i - 1] - nums[i - 1]);
        }
        return dp1[n];
    }
};
