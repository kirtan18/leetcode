// https://leetcode.com/contest/weekly-contest-274/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long n = a.size();
        if(mass < a[0]){
            return false;
        }
        long long check = mass + a[0];
        
        for(long long i=1;i<n;i++){
            if(check >= a[i]){
                check += a[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};


///////////////////// Optimal ////////////////////////
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        int n = asteroids.size();
        sort(begin(asteroids), end(asteroids));
        
        long long planetMass = mass;
        
        for(auto& asteroid : asteroids) {
            if(planetMass < asteroid) return false; 
			planetMass += asteroid;
        }
        return true;
    }
};
