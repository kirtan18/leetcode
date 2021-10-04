https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/maximum-sum-non-adjacent-elements-official/ojquestion

#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    int inc = a[0];
    int exc = 0;
    
    for(int i = 1 ; i < n ; i++){
        int newInc = exc + a[i];
        int newExc = max(inc,exc);
        
        inc = newInc;
        exc = newExc;
    }
    cout << max(inc,exc) << "\n";
    return 0;
}
