https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/
//////////////////////////////////////////////////////////////////////////////////
Brute Force
T.C = O(N^2)
S.C = O(N^2)
  
#define MAX 100
int dp[MAX][MAX];

int countRemoval(int a[],int i,int j,int k){
    if(i >= j)return 0;
    else if((a[j] - a[i]) <= k)return 0; 
    else if(dp[i][j] != -1)return dp[i][j];
    else if((a[j] - a[i]) > k){
        dp[i][j] = 1 + min(countRemoval(a,i+1,j,k), 
                           countRemoval(a,i,j-1,k));
    }
    return dp[i][j];
}


int removal(int a[] , int n , int k){
   sort(a,a+n);
   memset(dp,-1,sizeof (dp));
   if(n == 1){
     return 0; 
   }
   else{
    return countRemoval(a,0,n-1,k);
   }
}

void solve(){
    int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removal(a, n, k); 
}  


////////////////////////////////////////////////////////////////////////////////////
Optimal 
T.C =  O(NlogN)
S.C = O(1)
  

void solve(){
    
    int n; cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int k;
    cin >> k;
    sort(a,a+n);
    if(n == 1)cout << 0;
    else{
        int ans = n-1;
        for(int i=0;i<n;i++){
            int j = upper_bound(a+i,a+n,a[i]+k)-a-1;
            ans = min(ans,n-(j-i+1));
            cout << ans << " ";
        }
        cout << ans;
    }    
}  
