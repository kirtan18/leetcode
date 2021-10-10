https://leetcode.com/contest/weekly-contest-262/problems/minimum-operations-to-make-a-uni-value-grid/


class Solution {
    
    int solve(int need , int x , vector<int>&tmp){
        int cnt = 0;
        
        for(int i = 0 ; i < tmp.size() ; i++){
            int diff = abs(tmp[i] - need);
            if(diff % x != 0)return -1;
            cnt += (diff / x);
        }
        return cnt;
    }
    
public:
    int minOperations(vector<vector<int>>& grid, int x){
        
        vector<int>temp;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int n = temp.size();
        int mid = temp[n/2];
        int ans = solve(mid,x,temp);
        return ans;
    }
};
