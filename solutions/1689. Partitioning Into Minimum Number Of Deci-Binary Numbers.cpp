class Solution {
public:
    
 /*   first  remember all ascii val     
'0' => 48 
'1' => 49 
'2' => 50 
'3' => 51 
'4' => 52 
'5' => 53 
'6' => 54 
'7' => 55 
'8' => 56 
'9' => 57 
    
    using asciii  val  in this  here  means  
        1.   ans = 51(3) - 48(0)  = 3  here   max(3,0) = 3     0 rep = 48(ascii val)
        2.   ans = 52(2) - 48(0)  = 2  here   max(2,3) = 3
         
        
        so ans  is   3   in first case ans  same  here  to all cases  try  it  your self to dry run 
          */
     
    int minPartitions(string n) {
         int answer=0;
        
        for (char c: n) answer = max(c-'0',answer);
        
        return answer;
    }
};
​
/*
 second approch
​
        temp=0;
        int mx=0;
      for(int i=0;i<s.size();i++)
      {
          temp=s[i]-'0';
          mx=max(temp, mx);
      }
        return mx;
        
      }
      
      */
