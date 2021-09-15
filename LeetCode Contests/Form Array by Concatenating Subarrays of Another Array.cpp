https://leetcode.com/contest/biweekly-contest-46/problems/form-array-by-concatenating-subarrays-of-another-array/



class Solution {
public:
    bool canChoose(vector<vector<int>>& grp , vector<int>& nums) {
        
        int start = 0 , i = 0 , cnt = 0;
        
        while(i < grp.size() && start < nums.size()){
            
            bool flag = false;
            for(int k = 0 ; k < grp.size() ; k++){
                if(grp[i][k] != nums[start+k]){
                    flag = true;
                    break;
                }
            }
            
            if(flag == false){
                start = start + grp.size();
                i++;
                cnt++;
            }
            else{
                start++;
            }
        }
        if(cnt == grp.size()){
            return true;
        }
        else{
            return false;
        }
    }
};
