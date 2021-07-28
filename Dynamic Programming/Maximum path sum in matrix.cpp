https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#


 int maximumPath(int n, vector<vector<int>> Matrix)
    {   
        for(int row = n-2 ; row >= 0 ; row--){
            for(int col = 0 ; col < n ; col++){
               
                int down = Matrix[row+1][col];
                int down_left = (col == 0) ? 0 : Matrix[row+1][col-1];
                int down_right = (col == n-1) ? 0 : Matrix[row+1][col+1];
                
                Matrix[row][col] = Matrix[row][col] + max(down,max(down_left,down_right));
            }
        }
        
        int maxi = Matrix[0][0];
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi,Matrix[0][i]);
        }
        return maxi;
    }
