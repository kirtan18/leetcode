https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1#


 int maxSquare(int n, int m, vector<vector<int>> mat){
        int ans=0;
        for(int i=0;i<mat.size();++i)
        {
            if(mat[i][0]==1)
               ans=1;
        }
        
        for(int i=0;i<mat[0].size();++i)
          {
              if(mat[0][i]==1)
                 ans=1;
                
          }
          
        for(int i=1;i<mat.size();++i)
        {
            for(int j=1;j<mat[i].size();++j)
            {
                if(mat[i][j]==0)
                   continue;
                   
                else
                  {
                      mat[i][j]=min({mat[i-1][j],mat[i-1][j-1],mat[i][j-1]})+1;
                      ans=max(ans,mat[i][j]);
                  }
            }
        }
        
        return ans;
    }
