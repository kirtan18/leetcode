https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int miniJump = 0;
        
        for(int i = nums.size()-2 ; i >= 0 ; i--){
            miniJump++;
            if(nums[i] >= miniJump){
                miniJump = 0;
            }
        }
        if(miniJump == 0){
            return true;
        }
        else{
            return false;
        }
    }
};
