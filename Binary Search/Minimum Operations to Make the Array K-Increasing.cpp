// https://leetcode.com/contest/weekly-contest-272/problems/minimum-operations-to-make-the-array-k-increasing/


class Solution {
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>seq;
        seq.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(seq.back() <= nums[i]){
                seq.push_back(nums[i]);
            }
            else{
                int ind = upper_bound(seq.begin(),seq.end(),nums[i]) - seq.begin();
                seq[ind] = nums[i];
            }
        }
        return seq.size();
    }
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<k;i++){
            vector<int>temp;
            for(int j=i;j<n;j+=k) {
                temp.push_back(arr[j]);
            }
            int curr = lengthOfLIS(temp);
            ans += (temp.size() - curr);
        }
        return ans;
    }
};
