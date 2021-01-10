#include<bits/stdc++.h>
class Solution {
public:
    
    // using two pointer
     // time == O(n)   space == O(1) 
    void reverseString(vector<char>& s) {
      
        int left =0;
        int right = s.size()-1;
        
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            left += 1;
            right -= 1;
        }
        
    }
};
​
