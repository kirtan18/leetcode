// https://www.interviewbit.com/problems/scramble-string/


/////////////////////////////////////////////////////////// Recursion (TLE)  || T.C = O() || S.C = O()  //////////////////////////////////////


bool solve(string a, string b){

    if(a.compare(b) == 0)return true;
    if(a.length() <= 1)return false;

    int n = a.length();
    bool flag = false;

    for(int i = 1 ; i <= n-1 ; i++){
        
        if((solve(a.substr(0,i) , b.substr(n-i,i)) == true && 
              solve(a.substr(i,n-i) , b.substr(0,n-i)) == true)  || 
            
             (solve(a.substr(0,i) , b.substr(0,i)) == true && 
              solve(a.substr(i,n-i) , b.substr(i,n-i)) == true)
            ){
                flag = true;
                break;
            }
     }
    return flag;
}

int Solution::isScramble(const string a, const string b) {
    if(a.length() != b.length())return false;
    if(a.length() == 0 && b.length() == 0)return true;

    return solve(a,b);
}


/////////////////////////////////////////////////////  Optimal || using Map || T.C = O() || S.C = O() /////////////////////////////////////////////////////////

unordered_map<string,bool>mp;

bool solve(string a, string b){

    if(a.compare(b) == 0)return true;
    if(a.length() <= 1)return false;

    string key = a + ' ' + b;

    if(mp.find(key) != mp.end()){
        return mp[key];
    }

    int n = a.length();
    bool flag = false;

    for(int i = 1 ; i <= n-1 ; i++){
        
        if( (solve(a.substr(0,i) , b.substr(n-i,i)) == true && 
              solve(a.substr(i,n-i) , b.substr(0,n-i)) == true)  || 
            
             (solve(a.substr(0,i) , b.substr(0,i)) == true && 
              solve(a.substr(i,n-i) , b.substr(i,n-i)) == true)
            ){
                flag = true;
                break;
            }
     }
    return mp[key] = flag;
}

int Solution::isScramble(const string a, const string b) {
    if(a.length() != b.length())return false;
    if(a.length() == 0 && b.length() == 0)return true;

    return solve(a,b);

}
 
