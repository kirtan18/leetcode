https://leetcode.com/contest/weekly-contest-269/problems/k-radius-subarray-averages/



class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n,-1);
        vector<long long>pre(n,0);
        long long a = 0;
        
        for(int i=0;i<n;i++){
            a += nums[i];
            pre[i] = a;
        }
        
        for(int i=0;i<n;i++){
            if(i-k < 0 || i+k >= n){
                continue;
            }
            else{
                if(i-k == 0){
                    res[i] = pre[i+k] / (2*k+1);
                }
                else{
                    res[i] = (pre[i+k] - pre[i-k-1]) / (2*k+1); 
                }
            }
        }
        return res;
        
    }
};
