https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/target-sum-subsets-dp-official/ojquestion


//////////////////////////////////////////////////// Mine Approch ////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;


void solve(){
     int n;cin >> n;
     int a[n];
     for(int i = 0 ; i < n ; i++){
        cin >> a[i];
     }
     int target;
     cin >> target;

     bool dp[n+1][target+1];

     for(int i = 0 ; i <= n+1 ; i++){
         for(int j = 0 ; j <= target+1 ; j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
            
            if(a[i-1] <= j){
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
         }
     }
     if(dp[n][target] == 1){
         cout << "true" <<"\n";
     }else{
         cout << "false" <<"\n";
     }
}

int main(){
    solve();
    return 0;
}

/////////////////////////////////////////////// Peepcoding Approch //////////////////////////////////////////////////////


#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;


void solve(){
     int n;cin >> n;
     int a[n];
     for(int i = 0 ; i < n ; i++){
        cin >> a[i];
     }
     int target;
     cin >> target;

     bool dp[n+1][target+1];

     for(int i = 0 ; i < n+1 ; i++){
         for(int j = 0 ; j < target+1 ; j++){
            if(i==0 && j == 0){
                dp[i][j] =true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }
            else if(j == 0){
                dp[i][j] = true;
            }
            
            else{
                if(dp[i-1][j] == true){
                    dp[i][j] = true;
                }
                else{
                    int val = a[i-1];
                    if(j >= val && dp[i-1][j-val] == true){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
         }
     }
     if(dp[n][target] == 1){
         cout << "true" <<"\n";
     }
     else{
         cout << "false" <<"\n";
     }
}

int main(){
    solve();
    return 0;
}



