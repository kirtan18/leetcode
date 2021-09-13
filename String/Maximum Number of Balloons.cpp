https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3973/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
          int b,a,n,o,l;
          b = a = n = o = l = 0;
            
          for(auto ch : text){
              b += (ch == 'b');
              a += (ch == 'a');
              n += (ch == 'n');
              o += (ch == 'o');
              l += (ch == 'l');
              
          }  
         return min({b,a,n,o/2,l/2});
            
    }
};
