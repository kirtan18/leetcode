https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/coin-change-permutations-official/ojquestion

int main(){
    int n;
    cin >> n;
    int coins[n];
    for(int i = 0 ; i < n ; i++){
        cin >> coins[i];
    }
    
    int tar;
    cin >> tar;
    vector<int>dp(tar+1,0);
    dp[0] = 1;
    
    for(int amt=1;amt<=tar;amt++){
        for(int coin : coins){
            if(coin <= amt){
                int rem = amt - coin;
                dp[amt] += dp[rem];
            }
        }
    }
    
    cout << dp[tar] <<"\n";
    return 0;
}
