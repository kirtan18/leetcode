https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-variable-jumps-official/ojquestion


#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    vector<int>dp(n+1);
    dp[n] = 1;
    
   for (int i = n - 1; i >= 0; i--) {
      for (int reach = i + 1; reach <= min(n, i + arr[i]); reach++) {
        dp[i] += dp[reach];
      }
    }
    cout << dp[0] << "\n";
    return 0;
}
