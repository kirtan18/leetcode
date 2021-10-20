https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-official/ojquestion

#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    long n;
    cin >> n;
    long a[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    
    long dp[n][3];
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    
    for(int i=1;i<n;i++){
        dp[i][0] = a[i][0] + min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = a[i][1] + min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = a[i][2] + min(dp[i-1][0],dp[i-1][1]);
    }
    
    long ans = min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    cout << ans << "\n";
    return 0;
}
