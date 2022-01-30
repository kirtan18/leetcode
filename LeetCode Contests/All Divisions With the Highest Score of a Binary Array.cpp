// https://leetcode.com/contest/weekly-contest-278/problems/all-divisions-with-the-highest-score-of-a-binary-array/

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(0);
        int n = nums.size();
        int totalOne = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1)totalOne++;
        }
        
        int sum = 0;
        int maxSum = totalOne;
        int leftzero = 0,leftone = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0)leftzero++;
            else leftone++;
            sum = leftzero + (totalOne - leftone);
            
            if(sum > maxSum){
                maxSum = sum;
                ans = {i+1};
            }
            else if(sum == maxSum){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
