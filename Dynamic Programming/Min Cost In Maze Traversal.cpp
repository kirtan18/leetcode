https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/min-cost-maze-traversal-official/ojquestion

// Let us say the position of the current cell is (i, j) then
// Moving 1 cell right will lead us to (i, j + 1)th cell
// Moving 1 cell down will lead us to (i + 1, j)th cell
// Let cost(i,j) represent the cost at (i,j)th cell and min_cost(i, j) represent the minimum cost to reach destination from the (i,j)th cell.
// From (i,j)th cell we can move to either (i, j+1) or (i+1, j)
// Now to reach the destination with minimum cost we will move in such a direction which will lead us to the destination with minimum cost as follows
// min_cost(i, j) = cost(i, j) + MIN{min_cost(i, j+1), min_cos{i+1, j}}
// DP tabulation:
// 1.Create the dp table with same dimension as the given cost matrix
// 2.dp[i][j] represent the minimum cost to reach destination from the (i,j)th cell
// Recursive equation in terms of dp table can be written as follows
// dp[i][j] = cost[i][j] + min(dp[i][j + 1], dp[i + 1][j])
// 3.Base conditions:
// From any cell which belongs to the last row, we can move only in the right direction to reach the destination. ie.,
// dp[n-1][j] = cost[n-1][j] + dp[n-1][j+1]
// From any cell which belongs to the last column, we can move only in the down direction to reach destination i.e.,
// dp[i][m-1] = cost[i][m-1] + dp[i+1][m-1]
// Minimum cost to reach destination from (0, 0) is in dp[0][0]



#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    int cost[n][m];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;  j < m ; j++){
            cin >> cost[i][j];
        }
    }
    
    int dp[n+1][m+1];
    dp[n-1][m-1] = cost[n-1][m-1];
    
    // fill the last row
    for(int j = m-2 ; j >= 0 ; j--){
        dp[n-1][j] = cost[n-1][j] + dp[n-1][j+1];
    }
    
    //fill the last col
    for(int i = n-2; i >= 0 ; i--){
        dp[i][m-1] = cost[i][m-1] + dp[i+1][m-1];
    }
    
    // fill the remain cells
    
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = m-2 ; j >=0 ; j--){
            dp[i][j] = cost[i][j] + min(dp[i][j+1] ,dp[i+1][j]);
        }
    }
    cout << dp[0][0] <<"\n";
    return 0;
}
