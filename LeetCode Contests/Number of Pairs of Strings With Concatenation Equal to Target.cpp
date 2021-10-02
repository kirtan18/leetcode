https://leetcode.com/contest/biweekly-contest-62/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        
        int cnt = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            string check = nums[i];
            for(int j = 0 ; j < nums.size() ; j++){
                if(i == j){
                    continue;
                }
                else if(check + nums[j] == target){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
