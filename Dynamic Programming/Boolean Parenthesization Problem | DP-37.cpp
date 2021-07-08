// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

/////////////////////////////////////////////////////  Using Rec || T.C = O(n^2) || S.C = O(1)  //////////////////////////////////////////////

class Solution{
    
    int solve(int i,int j,string s,bool istrue){
        
        if(i>j)return 0;
        if(i == j){
            if(istrue == true){
                return s[i]=='T';
            }
            else{
                return s[j]=='F';
            }
        }
        
        int ans = 0;
        
        for(int k = i+1 ; k <= j-1 ; k += 2){
            int lt = solve(i,k-1,s,true);
            int lf = solve(i,k-1,s,false);
            int rt = solve(k+1,j,s,true);
            int rf = solve(k+1,j,s,false);
            
            
            if(s[k] == '&'){
                if(istrue == true){
                    ans = ans+ lt * rt;
                }
                else{
                    ans += lf * rt + lt * rf + lf * rf;
                }
            }
            
            else if(s[k] == '|'){
                if(istrue == true){
                    ans += lt * rt + lt * rf + lf * rt;
                }
                else{
                    ans += lf * rf;
                }
            }
            
            else if(s[k] == '^'){
                if(istrue == true){
                    ans += lf * rt + lt * rf;
                }
                else{
                    ans += lf * rf + lt * rt;
                }
            }
            // cout << ans <<" ";
        }
        return ans;
    }
    
    
    
public:
    int countWays(int N, string S){
        return solve(0,N-1,S,true);
    }
};


//////////////////////////////////////////////////////  Bottom Up || T.C =O(N^2)   || S.C = O(N) || Not working in gfg //////////////////////////////////////////////////////////////

class Solution{
    unordered_map<string,int>mp;
    int solve(int i,int j,string s,bool istrue){
        
        if(i>j)return 0;
        if(i == j){
            if(istrue == true){
                return s[i]=='T';
            }
            else{
                return s[j]=='F';
            }
        }
        
       string temp=to_string(i)+" "+to_string(j)+" "+to_string(istrue);
        
        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }
        
        
        int ans = 0;
        
        for(int k = i+1 ; k <= j-1 ; k += 2){
            int lt = solve(i,k-1,s,true);
            int lf = solve(i,k-1,s,false);
            int rt = solve(k+1,j,s,true);
            int rf = solve(k+1,j,s,false);
            
            
            if(s[k] == '&'){
                if(istrue == true){
                    ans = ans+ lt * rt;
                }
                else{
                    ans += lf * rt + lt * rf + lf * rf;
                }
            }
            
            else if(s[k] == '|'){
                if(istrue == true){
                    ans += lt * rt + lt * rf + lf * rt;
                }
                else{
                    ans += lf * rf;
                }
            }
            
            else if(s[k] == '^'){
                if(istrue == true){
                    ans += lf * rt + lt * rf;
                }
                else{
                    ans += lf * rf + lt * rt;
                }
            }
            // cout << ans <<" ";
            
        }
        return mp[temp] = ans;
    }
    
    
    
public:
    int countWays(int N, string S){
        mp.clear();
        return solve(0,N-1,S,true);
    }
};





