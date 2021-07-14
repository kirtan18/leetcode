https://leetcode.com/problems/decode-ways/


////////////////////////////////////////////////  Recursion  || T.C = O() TLE || S.C = O(1)  ////////////////////////////////////////////////

 class Solution {
    
    int help(int i ,string &s){
        
        if( i >= s.size())return 1;
        
        int op1 = s[i] - '0';
        int op2 = 0;
        int ans = 0;
        
        if(i < s.size() -1){
            op2 = op1*10 + s[i+1] - '0';
        }
        
        if(op1 > 0) ans += help(i+1,s);
        if(op1 > 0 && op2 <= 26 && op2 > 0) ans += help(i+2,s);
        return ans;      
    }

public:
    int numDecodings(string s) {
        return help(0,s);
    }
};


///////////////////////////////////////////////  Memoization || T.C = O()  || S.C = O(N)  //////////////////////////////////////////////////

class Solution {
    
    int help(int i ,string &s , vector<int>&mem){
        
        if( i >= s.size())return 1;
        if(mem[i]  != -1)return mem[i];
        
        int op1 = s[i] - '0';
        int op2 = 0;
        int ans = 0;
        
        if(i < s.size() -1){
            op2 = op1*10 + s[i+1] - '0';
        }
        
        if(op1 > 0) ans += help(i+1,s,mem);
        if(op1 > 0 && op2 <= 26 && op2 > 0) ans += help(i+2,s,mem);
        return mem[i] = ans;      
    }

public:
    int numDecodings(string s){
        int n = s.size();
        vector<int>mem(n+1,-1);
        return help(0,s,mem);
    }
};


/////////////////////////////////////////////////////  Bottom UP  || T.C = O(N) || S.C = O(N) /////////////////////////////////////////////////////////

class Solution {
public:
    int numDecodings(string s) {
        
       int dp[102];
       memset(dp,0,sizeof dp); 
       int n = s.size();
       
       dp[n+1] = 1;
       dp[n] = 1;
        
       for(int i = n-1 ; i >= 0 ; i--){
           
           int op1 = s[i]-'0';
           int op2 = 0;
           if(i < s.size()-1){
                op2 = op1 * 10 + s[i+1]-'0';
           }
           
           if(op1 > 0) dp[i] += dp[i+1];
           if(op1 > 0 && op2 > 0 && op2 <= 26) dp[i] += dp[i+2];                   
       }  
        return dp[0];       
    }
};






