// https://leetcode.com/contest/weekly-contest-263/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
   
    void solve(vector<int>& nums , int i,int temp,int &cnt , int &tar){
        if(i >= nums.size()){
            if(temp == tar){
                cnt++;
            }
            return;
        }
        solve(nums,i+1,temp,cnt,tar);
        solve(nums,i+1,(temp | nums[i]),cnt,tar);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        int cnt = 0; 
        
        for(auto it : nums){
            ans |= it;
        }
        
        solve(nums,0,0,cnt,ans);
        return cnt;
    }
};
