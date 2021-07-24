https://leetcode.com/contest/weekly-contest-250/problems/add-minimum-number-of-rungs/



class Solution {
public:
    int addRungs(vector<int>& v, int dist) {
        
        long long ans = 0 , p = 0;
        
        for(int i = 0 ; i < v.size() ; i++){
            
            long long m = (v[i] - p + dist - 1) / dist;
            ans += m-1;
            p = v[i];
        }
        return ans;
    }
};
