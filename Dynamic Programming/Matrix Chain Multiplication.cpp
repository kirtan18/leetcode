// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#



//////////////////////////////////////////////////////  Recursion  //////////////////////////////////////////////////////////

class Solution{
public:
    int solve(int arr[] , int i , int j){
        
        if( i == j)return 0;
        
        int k;
        int tempAns;
        int min = INT_MAX;
        for( k = i ; k < j ; k++){
            tempAns = solve(arr,i,k) +
                          solve(arr,k+1,j) +
                          arr[i-1]*arr[k]*arr[j];
                          
            if(tempAns < min){
                min = tempAns;
            }              
        }
        return min;
    }
    
    
    int matrixMultiplication(int N, int arr[])
    { 
        return solve(arr,1,N-1);
    }
};

/////////////////////////////////////////////   Bottom UP  ////////////////////////////////////////////

class Solution{
public:
    
    int dp[1001][1001];
    int solve(int arr[] , int i , int j){
        
        if( i == j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        dp[i][j] = INT_MAX;
        for(int k = i ; k < j ; k++){
            dp[i][j] = min(dp[i][j] , solve(arr,i,k) + solve(arr,k+1,j) +
                       arr[i-1]*arr[k]*arr[j]);              
        }
        return dp[i][j];
    }
    
    
    int matrixMultiplication(int N, int arr[])
    {  
        memset(dp,-1,sizeof dp);
        return solve(arr,1,N-1);
    }
};





















