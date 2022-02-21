// https://leetcode.com/contest/weekly-contest-280/problems/removing-minimum-number-of-magic-beans/


class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long total = 0;
        long long ans = 1e18;
        long long n = beans.size();
        
        sort(beans.begin(),beans.end());
        
        for(auto it : beans)total += it;
        
        for(long long i = 0 ; i < n ; i++){
            long long change = total - (n-i) * (long long)beans[i] * 1LL;
            ans = min(ans,change);
        }
        return ans;
    }
};
