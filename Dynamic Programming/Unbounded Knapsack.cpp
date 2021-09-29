https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

int knapSack(int N, int W, int val[], int wt[])
    {
         int dp[W+1];
         memset(dp, 0, sizeof dp);

     for (int i=0; i<=W; i++)
       for (int j=0; j<N; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
     return dp[W];
    }

///////////////////////////////////////////////////////////////////////

int main(){
    int n;
    cin >> n;
    int wt[n];
    int val[n];
    
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int tar;
    cin >> tar;
    vector<int>dp(tar+1,0);
    
    for(int bag = 0 ; bag <= tar ; bag++){
        for(int i = 0 ; i < n ; i++){
            if(val[i] <= bag){
                dp[bag] = max(dp[bag],dp[bag-val[i]] + wt[i]);
            }
        }
    }
   
    cout << dp[tar] << "\n";
    
    return 0;
}
