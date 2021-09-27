https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-minimum-moves-official/ojquestion

#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    vector<int> dp(n+1,-1);
    dp[n] = 0;
    for(int i=n-1;i>=0;i--){
        if(arr[i] > 0){
            int minn = INT_MAX;
            
            for(int j=1;j<=arr[i] && i+j < dp.size();j++){
                if(dp[i+j] != -1){
                    minn = min(minn,dp[i+j]);
                }
            }
            
            if(minn != INT_MAX){
                dp[i] = minn + 1;
            }
        }
    }
    
    cout <<  dp[0] << "\n";
    
}
