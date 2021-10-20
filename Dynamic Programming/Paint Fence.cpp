https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-fence-official/ojquestion


#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  
  int n,k;
  cin >> n >> k;
  
  long same = k * 1;
  long diff = k * (k-1);
  long total = same + diff;
  
  for(int i = 3 ; i <= n ; i++){
      same = diff * 1;
      diff = total * (k-1);
      total = same + diff;
  }
  
  cout << total << "\n";
  return 0;
}
