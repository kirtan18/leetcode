class Solution {
public:
    /*
    int tribonacci(int n) {
​
        //int f[38] = {0};
​
        f[0] = 0;
        f[1] = f[2] = 1;
​
        for(int i=3;i<=n;i++) 
            f[i] = f[i-1] + f[i-2] + f[i-3];
​
        return f[n];
    }
};
*/
  int tribonacci(int n) {
        int first=0,second=1,third=1,sum;
        
        if(n<=1){
            return n;
        }
        if(n==2){
            return 1;
        }
        
       else{
            for(int i=2;i<n;i++){
                sum=first+second+third;
                first=second;
                second=third;
                third=sum;
            }            
             
