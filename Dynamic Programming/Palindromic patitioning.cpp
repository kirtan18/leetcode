// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1


/////////////////////////////////////////////////   Recursive (TLE)  ////////////////////////////////////////////

class Solution{
    
    bool isPalindrome(string String, int i, int j)
   {
        while(i < j)
        {
        if(String[i] != String[j])return false; 
           i++;
           j--;
        }
        return true;
   }
    
    int partition(int i , int j ,  string s){
        
        if(i >= j)return 0;
        
        if(isPalindrome(s,i,j) == true)return 0;
        
        int mini = INT_MAX;
        for(int k = i ; k < j ; k++){
            
            int tempAns = partition(i,k,s) +
                          partition(k+1,j,s) + 1;
                          
            mini = min(mini,tempAns);              
        }
        return mini;
    }
    
    
public:
    int palindromicPartition(string str)
    {
        int n = str.size(); 
        return partition(0,n-1,str);
    }
};


////////////////////////////////////////////////////  Optimal  //////////////////////////////////////////////////////////


class Solution{
    int dp[1001][1001];
    int left,right;
    bool isPalindrome(string String, int i, int j)
   {
        while(i < j)
        {
        if(String[i] != String[j])return false; 
           i++;
           j--;
        }
        return true;
   }
    
    int partition(int i , int j ,  string s){
        
        if(i >= j)return 0;
        
        if(isPalindrome(s,i,j) == true)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
         dp[i][j] = INT_MAX;
        for(int k = i ; k < j ; k++){
            
            if(dp[i][k] != -1){
                left = dp[i][k];
            }else{
                left=partition(i,k,s);
            }
            
            if(dp[k+1][j] != -1){
                right = dp[k+1][j];
            }else{
                right = partition(k+1,j,s);
            }
            
            dp[i][j] = min (dp[i][j] ,  1 + left + right);
        }
        return dp[i][j];
    }
    
    
public:
    int palindromicPartition(string str)
    {   
        memset(dp,-1,sizeof dp);
        int n = str.size(); 
        return partition(0,n-1,str);
    }
};






