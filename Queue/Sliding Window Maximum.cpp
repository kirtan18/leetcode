// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        map<int,int,greater<int>>mp;
        
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        auto it = mp.begin();
        ans.push_back(it->first);
        
        for(int i=k;i<n;i++){
            
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0){
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            auto it = mp.begin();
            ans.push_back(it->first);
        }
        return ans;
    }
};
