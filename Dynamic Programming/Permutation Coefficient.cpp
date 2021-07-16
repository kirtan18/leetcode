   


/////////////////////////////////////////////////////////////  using DP  || T.C = O(N) || S.C =O(N) //////////////////////////////////

int permutation(int n , int k){
    int dp[n+1];
    dp[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        dp[i] = i * dp[i-1]; 
    }

    return dp[n] / dp[n-k];
}

/////////////////////////////////////////////////////////using pointer  || T.C = O(N) || S.C = O(1)  ///////////////////////////////////

int permutation(int n , int k){
    int p = 1;

    for(int i = 0 ; i < k ; i++){
        p *= (n-i);
    }

    return p;
}
