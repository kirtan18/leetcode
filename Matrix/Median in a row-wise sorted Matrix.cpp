// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

/////////////////////////////////////////////////////  Brute Force || T.C = O(n^2) || Space = O(n)  ///////////////////////////////////////////////

   int median(vector<vector<int>> &matrix, int r, int c){
        vector<int>ans;
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
               ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        int mid = (r * c)/2;
        return ans[mid];
        
    }


///////////////////////////////////////////////  Optimal || T.C =  || Space =     //////////////////////////////////////////////////////
