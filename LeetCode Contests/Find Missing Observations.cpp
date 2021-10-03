https://leetcode.com/contest/weekly-contest-261/problems/find-missing-observations/


class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        vector<int>ans;
        for(auto x : rolls)sum += x;
        int req = (mean * (n+m)) - sum;
        if(req < n || req >(6*n)) return ans;
        int p = req / n;
        ans.resize(n,p);
        int rem = req % n;
        for(int i = 0 ; i < rem ; i++){
            ans[i] += 1;
        }
        return ans;
    }
};
