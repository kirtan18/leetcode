https://leetcode.com/contest/weekly-contest-258/problems/number-of-pairs-of-interchangeable-rectangles/

///////////////////////////////////////////  Using Map  /////////////////////////////////////////////

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        int n = rectangles.size();
        unordered_map<double,long long>mp;
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            double p = (double)rectangles[i][0] / rectangles[i][1];
            ans += mp[p];
            mp[p]++;
        }
        return ans;
    }
};

////////////////////////////////////////// Using GCD //////////////////////////////////////////////

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& A) {
        int  n = A.size();
        long long ans = 0;
        map<pair<int, int>, long long> M;
        for(auto &r: A){
            int gcd = __gcd(r[0], r[1]);
            r[0] /= gcd;
            r[1] /= gcd;
            M[{r[0], r[1]}]++;
        }
        for(auto c: M){
            ans += (c.second * (c.second - 1) )/ 2;
        }
        return ans;
    }
};
