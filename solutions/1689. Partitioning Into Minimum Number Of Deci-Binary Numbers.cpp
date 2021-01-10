class Solution {
public:
    int minPartitions(string n) {
         int answer=0;
        
        for (char c: n) answer = max(c-'0',answer);
        
        return answer;
    }
};
​
/*
​
​
t temp=0;
        int mx=0;
      for(int i=0;i<s.size();i++)
      {
          temp=s[i]-'0';
          mx=max(temp, mx);
      }
        return mx;
        
      }
      
      */
