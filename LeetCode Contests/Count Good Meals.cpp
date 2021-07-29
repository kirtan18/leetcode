https://leetcode.com/contest/weekly-contest-222/problems/count-good-meals/

/////////////////////////////////////////////////////////// Brute Force || T.C = O(N^2) || S.C = O(N) ///////////////////////////////////////////////////////////////////

class Solution {
public:
    int countPairs(vector<int>& adj) {
        
        int ans = 0;
        unordered_map<int,int>mp;
        for(auto i : adj)mp[i]++;
        
        for(auto x : adj){
            for(int i = 0 ; i <= 21 ; i++){
                int z = 1<<i; // pow(2,i)
                // cout << z <<" ";
                int y = z-x;
                cout << y << x <<" ";
                if(y == x)ans += mp[y]-1;
                else ans += mp[y];
            }
        }
        return ans/2;
    }
};

///////////////////////////////////////////////////// Optimal || T.C = O() || S.C = O()  /////////////////////////////////////////////////////////////////

class Solution {
public:
    int countPairs(vector<int>& adj) {
        
        int ans = 0,MOD = 1000000007;
        unordered_map<int,int>mp; 
        sort(adj.begin(),adj.end());
        for(auto x : adj){
            for(int i = 0 ; i <= 21 ; i++){
                int z = 1<<i; // pow(2,i)
                int y = z-x;
                if(y > x)break;
                ans += mp[y];
                ans %= MOD;
            }
            mp[x]++;
        }
        return ans;
    }
};
