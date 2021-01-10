class Solution {
public:
    /***********  time = O(n)  space =O(1)   **************/
    
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
    
    
    
    
    
    
    
    
    /****************  using map *******************/
    
    // time == O(n)    , space == O(n)
    
  /*  
    int maxNumberOfBalloons(string text) {
        map<char,int> M;
        for(auto ch : text) M[ch]++;
