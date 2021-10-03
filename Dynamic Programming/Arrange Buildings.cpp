https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/arrange-buildings-official/ojquestion


//////////////////////////////////////////////  T.C = O(N) || S.C = O(1) ////////////////////////////////////////////////////
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int>a(n+1,0);
    vector<int>b(n+1,0);
    a[1] = 1;
    b[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        b[i] = b[i-1] + a[i-1];
        a[i] = b[i-1];
    }
    cout << a[n] + b[n] << " "; 
    return 0;
}

//////////////////////////////////// T.C = O(N) || S.C = O(N) ////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    long long int n;
    cin >> n;
    vector<long long int>a(n+1,0);
    vector<long long int>b(n+1,0);
    a[1] = 1;
    b[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        b[i] = b[i-1] + a[i-1];
        a[i] = b[i-1];
    }
 
    long long int total = a[n] + b[n];
    total = total * total;
    cout << total<<"\n";
    return 0;
}
