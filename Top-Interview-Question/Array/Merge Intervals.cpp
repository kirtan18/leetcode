// https://leetcode.com/problems/merge-intervals/

/////////////////////////////////////////// T.C = O(NlogN) || S.C = O(N)  ////////////////////////////////////

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& val) {
        vector<vector<int>>merge_interval;
        if(val.size() == 0)return merge_interval;
        
        sort(val.begin(),val.end());
        vector<int>temp = val[0];
        
        for(auto it : val){
            if(it[0] <= temp[1]){
                temp[1] = max(temp[1],it[1]);
            }
            else{
                merge_interval.push_back(temp);
                temp = it;
            }
        }
        merge_interval.push_back(temp);
        return merge_interval;
    }
};
