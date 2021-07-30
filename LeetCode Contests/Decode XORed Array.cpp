https://leetcode.com/contest/weekly-contest-223/problems/decode-xored-array/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        for(auto x : encoded){
            ans.push_back(first ^ x);
            first ^= x;
        }
        return ans;
    }
};
