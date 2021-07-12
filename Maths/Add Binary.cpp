https://leetcode.com/problems/add-binary/

//////////////////////////////////////////////////  T.C = O(a+b) || S.C = O(N)  /////////////////////////////////////////////////////////


class Solution {
public:
    string addBinary(string a, string b) {
       //for store the result         
        string result = "";
        //sum of digit
        int s = 0;
        
        int i = a.length()-1 , j = b.length()-1;
        
        while(i >= 0 || j >= 0 || s == 1){
            
           //means  1+1 = 2           
            s += ((i>=0) ? a[i]-'0' : 0 );
            s += ((j>=0) ? b[j]-'0' : 0 );
            
           //here we 2%2 == 0 means sum 0 and carry 1 is s so s/2              
            result = char(s % 2 + '0') + result;
            
            s /= 2;
            
            i--,j--;
        }
        return result;
    }
};
