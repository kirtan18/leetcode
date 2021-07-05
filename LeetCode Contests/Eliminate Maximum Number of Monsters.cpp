// https://leetcode.com/contest/weekly-contest-248/problems/eliminate-maximum-number-of-monsters/


// First find the time between city and monster then check the method ( Time = dist / speed )

  class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time;
        
        for(int i = 0 ; i < speed.size() ; i++){
            time.push_back((double)dist[i] / (double)speed[i]);
        }
        
        sort(time.begin() , time.end());
        
        int T = 0 , ans = 0;
        
        for(auto a : time){
            if(a <= T){
                break;
            }
            else{
                T++;
                ans++;
            }
        }
        return ans;
    }
};
