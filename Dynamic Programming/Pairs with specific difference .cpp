https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#

/////////////////////////////////////////////////////////////////////// T.C = O(NlogN) || S.C = O(1) /////////////////////////////////////////////////////

 int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr,arr+N,greater<int>());
        int i = 0;
        int s = 0;
        
        while(i < N-1){
            int x = abs(arr[i] - arr[i+1]);
            if(x < K){
                s += arr[i];
                s += arr[i+1];
                i += 2;
            }
            else{
                i++;
            }
        }
        return s;
    }


/////////////////////////////////////////////////////////////////////// T.C = O(NlogN) || S.C = O(N) /////////////////////////////////////////////////////////

Examples:

Input  : arr[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
Output : 62
Explanation:
Then disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17)  
So maximum sum which we can get is 3 + 5 + 12 + 10 + 15 + 17 = 62
Note that an alternate way to form disjoint pairs is, (3, 5), (9, 12), (15, 17), but this pairing produces lesser sum.

Input  : arr[] = {5, 15, 10, 300}, k = 12
Output : 25

  Pair up i with (i-1)th element, i.e. 
      dp[i] = dp[i-2] + arr[i] + arr[i-1]
  Don't pair up, i.e. 
      dp[i] = dp[i-1] 
Above iteration takes O(N) time and sorting of array will take O(N log N) time so total time complexity of the solution will be O(N log N) 



#include <bits/stdc++.h>
using namespace std;

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    sort(arr, arr+N);
 

    int dp[N];
 

    dp[0] = 0;
 
    for (int i = 1; i < N; i++)
    {
        // first give previous value to dp[i] i.e.
        // no pairing with (i-1)th element
        dp[i] = dp[i-1];
 
        // if current and previous element can form a pair
        if (arr[i] - arr[i-1] < K)
        {
            // update dp[i] by choosing maximum between
            // pairing and not pairing
            if (i >= 2)
                dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
            else
                dp[i] = max(dp[i], arr[i] + arr[i-1]);
        }
    }
 
    //  last index will have the result
    return dp[N - 1];
}
 
