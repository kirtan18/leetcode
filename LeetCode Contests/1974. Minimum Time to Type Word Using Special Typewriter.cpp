https://leetcode.com/contest/biweekly-contest-59/problems/minimum-time-to-type-word-using-special-typewriter/

class Solution {
public:
    int minTimeToType(string s) {
      int n = s.size(), ans = n;
      char pre = 'a';
      for (int i = 0; i < n; i++) {
        char cur = s[i];
        int dif = abs(cur - pre);
        ans += min(dif, 26 - dif);
        pre = cur;
      }
      return ans;
    }
};
