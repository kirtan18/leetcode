// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/


//////////////////////////////  Brute Force || T.C = O(N^2) || S.C = O(1) ////////////////////////////////////

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int cnt = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j]  < 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

///////////////////////////////////////  Optimal || T.C = O(m+n) || S.C = O(1) ////////////////////////////////////////////

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int i = grid.size()-1;
        int cnt = 0;
        int j = 0;
        
        while( i >= 0 && j < grid[0].size()){
            
            if(grid[i][j] < 0){
                cnt += grid[0].size() - j;
                i--;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};

/////////////////////////////////////////////////  Optimal | T.C = O(mlogn) || S.C = O(1) //////////////////////////////////////////

class Solution {
public:
    static int countNegativesHelper(const vector<int>& vec) {
        int low = 0;
        int high = vec.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid] >= 0) {
                // discard everything before mid which is non-negative
                low = mid + 1;
            } else {
                // discard everything after high which is negative
                high = mid - 1;
            }
        }
        // high is the index for the last non-negative number
        // high + 1 is the number of non-negative numbers
        // size - (high + 1) is the number of negative numbers
        return vec.size() - high - 1;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (int i=0; i<grid.size(); i++) {
            count += countNegativesHelper(grid[i]);
        }
        return count;
    }
};





