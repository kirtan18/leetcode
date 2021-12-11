// https://leetcode.com/contest/biweekly-contest-67/problems/find-subsequence-of-length-k-with-the-largest-sum/


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        int t = k,i=0;
        vector<int>ans;
        
        while(t != 0){
            ans.push_back(nums[i]);
            i++;
            t--;
        }
        
        for(int j=i;j<n;j++){
            int mini = min_element(ans.begin(),ans.end()) - ans.begin();
            if(ans[mini] < nums[j]){
                ans.erase(ans.begin()+mini);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};
