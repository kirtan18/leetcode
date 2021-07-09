https://leetcode.com/problems/longest-increasing-subsequence/

///////////////////////////////////////////////////  Brute Force || T.C = O(N^2) || S.C = O(N) ////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int ans = 1 , n = nums.size();
        vector<int>dp(n,1);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};



//////////////////////////////////////////////// Optimal || T.C = O(nlogn) || S.C = O(N) //////////////////////////////////////////

int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
