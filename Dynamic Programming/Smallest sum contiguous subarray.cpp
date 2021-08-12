https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/

///////////////////////////////////////////////////////////////////////////
void solve(){

    int n; cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
    int min_here = INT_MAX;
    int min_far = INT_MAX;

    for(int i = 0;i<n;i++){
        if(min_here > 0){
            min_here = arr[i];
        }
        else{
            min_here += arr[i];
        }
        min_far = min(min_far,min_here);
    }  
    cout << min_far;
}

//////////////////////////////////////////////////////////////////////////

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
  
    int dp[n];
    dp[0] = arr[0];
    int maxi = arr[0];

    for(int i = 1 ; i < n ; i++){
        dp[i] = min(arr[i] ,arr[i]+dp[i-1]);
        maxi = min(maxi,dp[i]);
    } 
    cout << maxi;
}
