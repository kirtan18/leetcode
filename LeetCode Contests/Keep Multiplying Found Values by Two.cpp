// https://leetcode.com/contest/weekly-contest-278/problems/keep-multiplying-found-values-by-two/


////////////////////////////////// itrative //////////////////////////////////
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        bool flag = true;
        while(flag == true){
            int i = 0;
            
            for(i=0;i<nums.size();i++){
                if(nums[i] == original){
                    original = 2 * original;
                    break;
                }
            }
            if(i == nums.size())flag = false;
        }
        
        return original;
    }
};

////////////////////////// Recursive ////////////////////////////////////

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        if(find(nums.begin(),nums.end(),original) != nums.end()){
            return findFinalValue(nums,original*2);
        }
        return original;
    }
};
