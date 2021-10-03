https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-encodings-official/ojquestion

#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int dp[n];
  dp[0] = 1;
  for (int i = 1 ; i < n ; i++) {
    if (s[i - 1] == '0' && s[i] == '0') {
      dp[i] = 0;
    }
    else if (s[i - 1] == '0' && s[i] != '0') {
      dp[i] = dp[i - 1];
    }
    else if (s[i - 1] != '0' && s[i] == '0') {
      if (s[i - 1] == '1' || s[i - 1] == '2') {
        dp[i] = (i >= 2 ? dp[i - 2] : 1);
      }
    }
    else {
      dp[i] = dp[i - 1];
      if (stoi(s.substr(i - 1, i + 1)) <= 26) {
        dp[i] += (i >= 2 ? dp[i - 2] : 1);
      }
    }
  }
  cout << dp[s.size() - 1] << "\n";
  return 0;
}
