https://leetcode.com/contest/weekly-contest-258/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/


class Solution {
    
    bool isPalindrome(string &s){
        int n = s.size();
        int i = 0 ;
        int j = n-1;
        
        while(i < j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    
    int solve(string &s , int n , string &s1, string &s2){
        
        if(n == 0){
            if(isPalindrome(s1) && isPalindrome(s2)){
                return s1.size() * s2.size();
            }
            return 0;
        }
        
        s1.push_back(s[n-1]);
        int ans1 = solve(s,n-1,s1,s2);
        cout << ans1 << " * ";
        s1.pop_back();
        s2.push_back(s[n-1]);
        int ans2 = solve(s,n-1,s1,s2);
        cout << ans2 <<" # ";
        s2.pop_back();
        int ans3 = solve(s,n-1,s1,s2);
        cout << ans3 <<" & ";
        return max({ans1,ans2,ans3});
        
    }
    
    
public:
    int maxProduct(string s) {
        int n = s.size();
        string s1 ,s2;
        int ans = solve(s,n,s1,s2);
        return ans;
    }
};
