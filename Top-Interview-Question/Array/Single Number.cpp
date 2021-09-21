https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/549/

////////////////////////////////////// Using Space /////////////////////////////////

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp[nums[i]] == 1){
                return nums[i];
            }
        }
        return 0;
    }
};


//////////////////////////// Constant Space ////////////////////////////////////


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
