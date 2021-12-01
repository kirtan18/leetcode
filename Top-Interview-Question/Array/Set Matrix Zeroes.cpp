// https://leetcode.com/problems/set-matrix-zeroes/

1. First approch is to find the zero in the matrix and then converte whole row and col in to '0' so Time comp :** O(N*M) * O(N+M)**
2. Second approch is to the create 2 dummy array first upper on the row and second right side on the col and put if where the val 0 in the matrix and then fill the values in dummy arrays
Time : O(M*N) + O(M*N)
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
3. Most Optimal APP : same as second method just use first row and col  like dummy array and put value in the first row and col 
Time : 2 * (m * n)
  
  class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int check = 1;
        
        for(int i=0;i<row;i++){
            if(mat[i][0] == 0)check = 0;
            for(int j=1;j<col;j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=1;j--){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
            if(check == 0)mat[i][0] = 0;
        }
    }
};
