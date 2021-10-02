https://leetcode.com/contest/biweekly-contest-62/problems/convert-1d-array-into-2d-array/


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
         if (original.size() != (m*n)){
            return ans;
        }
        
        int cnt =0;

        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {

                temp.push_back(original[cnt]);
                cnt++;
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
