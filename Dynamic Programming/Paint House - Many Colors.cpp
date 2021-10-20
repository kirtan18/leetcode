https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-many-colors-official/ojquestion


#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {

  long n, k;
  cin >> n >> k;
  long a[n][k];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
    }
  }

  long dp[n][k];

  for (int i = 0; i < k; i++) {
    dp[0][i] = a[0][i];
  }

  for(int i=1;i<n;i++){
      for(int j=0;j<k;j++){
          int mini = INT_MAX;
          for(int x=0;x<k;x++){
              if(x != j){
                  if(dp[i-1][x] < mini){
                      mini = dp[i-1][x];
                  }
              }
          }
          dp[i][j] = a[i][j] + mini;
      }
  }
  

  long ans = INT_MAX;
  for (int i = 0; i < k; i++) {
    ans = min(ans, dp[n - 1][i]);
  }
  cout << ans << "\n";

  return 0;
}
