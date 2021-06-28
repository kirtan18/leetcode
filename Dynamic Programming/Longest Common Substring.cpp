// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#


////////////////////////////////////////////////////////////  Top-Down /////////////////////////////////////////////////////////// 
//////////////////////////////////////////   Time : O(m*n) , Space : O(m*n) /////////////////////////////////////////////////////
 
 int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int dp[n+1][m+1];
        int result = 0;
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    result = max(result , dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
                
            }
        }
        return result;
    }



//////////////////////////////////////////////////  Recursive ////////////////////////////////////////////////////////  

string X, Y;


int lcs(int i, int j, int count)
{

    if (i == 0 || j == 0)
        return count;

    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}
