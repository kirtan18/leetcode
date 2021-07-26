https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/


int a[] = {3000, 2000, 1000, 3, 10};
int dp[10000];

int func(int n){
    if(n == -1)return 0;
    if(n == 0)return a[0];
    if(n == 1)return a[1] + a[0];
    if(dp[n] != -1) return dp[n];

   return dp[n] = max( max(func(n-1) , a[n] + func(n-2)) , 
               a[n] + a[n-1] + func(n-3));

}

void solve(){
    int n;
    n = 5;
    memset(dp,-1,sizeof (dp));
    func(n-1);
    cout << dp[n-1];
}
