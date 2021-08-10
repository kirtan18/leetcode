https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#

T.C = O(N*W)
S.C = O(N*W)

  
class Solution{
	int dp[1001][1001];	
    
    int func(int arr[],int n,int w){
        
        if(n == -1 and w == 0)return 0;
        if(n == -1)return 1e9;
        if(w == 0)return 0;
        if(dp[n][w] != -1)return dp[n][w];
        
        if( (n+1)>w or arr[n] == -1)return dp[n][w] = func(arr,n-1,w);
        int y = func(arr,n-1,w);
        int x = arr[n] + func(arr,n,w-(n+1));
        return dp[n][w] = min(x,y);
    } 
	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        memset(dp,-1,sizeof (dp));
        int x = func(cost,N-1,W);
        if(x >= 1e9)return -1;
        return x;
	} 
};  
  
