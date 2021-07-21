  ////////////////////////////////////////////////////////////////   Recursive Approch ///////////////////////////////////////////////////////////

  int lcs(int x, int y, string s1, string s2)
    {
        if(x == 0 || y == 0){
            return 0;
        }
        
        if(s1[x-1] == s2[y-1]){
            return  1 + lcs(x-1,y-1,s1,s2);
        }
        else{
            return max(lcs(x-1,y,s1,s2) , lcs(x,y-1,s1,s2));
        }
    }


//////////////////////////////////////////////////////////////// BottomUp (Memoization) /////////////////////////////////////////////////////////////


  public:
    //Function to find the length of longest common subsequence in two strings.
    int static dp[1001][1001];
    memset(dp,-1,sizeof(dp));
    int lcs(int x, int y, string s1, string s2)
    {
        if(x == 0 || y == 0){
            return 0;
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        if(s1[x-1] == s2[y-1]){
            return dp[x][y] =  1 + lcs(x-1,y-1,s1,s2);
        }
        else{
            return dp[x][y] = max(lcs(x-1,y,s1,s2) , lcs(x,y-1,s1,s2));
        }
        return dp[x][y];
    }


/////////////////////////////////////////////////////////////////// Up Down ////////////////////////////////////////////////////////


 int lcs(int x, int y, string s1, string s2)
    {   
        int  dp[x+1][y+1];
        
     
        for(int i = 0 ; i <= x ; i++){
            for(int j = 0 ; j <= y ; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
    
        return dp[x][y];
    }


//////////////////////////////////////////////////  Reduce Auxilary Space //////////////////////////////////////////////

class Solution
{
    public:
   
    int lcs(int x, int y, string s1, string s2)
    {
        
        int dp[2][y+1];
        
        bool bi;
        
        for(int i = 0 ; i <= x ; i++){
            
            bi = i & 1;
            
            for(int j = 0 ; j <= y ; j++){
                
                if( i == 0 || j == 0 ){
                    dp[bi][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[bi][j] = dp[1 - bi][j - 1] + 1;
                }
                else{
                    dp[bi][j] = max(dp[1-bi][j] , dp[bi][j-1]);
                }
            }
            
        }
        
        return dp[bi][y];
    }
};








