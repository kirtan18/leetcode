// https://leetcode.com/problems/subsets/

/////////////////////////////////// O(2*2^N)  //////////////////////////////////
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ans.push_back({});
        
        for(int i=0;i<nums.size();i++){
            int sz = ans.size();
            for(int j=0;j<sz;j++){
                vector<int>temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

/////////////////////////////////////// USing Backtracking O(2*2^N) ///////////////////////////
class Solution {
    void solve(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        else{
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
            solve(i+1,nums,temp,ans);
        }
    }
    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};
