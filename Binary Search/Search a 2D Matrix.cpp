https://leetcode.com/problems/search-a-2d-matrix/

///////////////////////////////////////  Brute force || T.C = O(N^2) || S.C = O(1) //////////////////////////////////////////

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};


////////////////////////////////////  Optimal || T.C = O(logn)  || S.C = O(1)  ///////////////////////////////////////////////


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0 , r = (m*n)-1;
        
        while(l <= r){
            
            int mid = (l+r)/2;
            
            if(matrix[mid/n][mid%n] == target){
                return true;
            }
            else if(matrix[mid/n][mid%n] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
};
