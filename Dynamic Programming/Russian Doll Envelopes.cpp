https://leetcode.com/problems/russian-doll-envelopes/


//////////////////////////////// T.C = O(N^2) /////////////////////////////

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& num) {
        int n = num.size();
        sort(num.begin(),num.end());
        
        vector<int>dp(n+1,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(num[j][0] < num[i][0] && num[j][1] < num[i][1]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};

//////////////////////////// T.C = O(NLogN) //////////////////////////////////////

class Solution {
public:

    static bool compare(vector<int> a, vector<int> b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        vector<int> dp;
        sort(env.begin(), env.end(), compare);
		
        for(int i=0;i<n;i++){
            cout << env[i][0] << " " << env[i][1] << "\n";
        }
        
        dp.push_back(env[0][1]);
        
        for(int i = 1; i < n; i++) {
            int cur = env[i][1];

            auto itr = lower_bound(dp.begin(), dp.end(), cur);
            
			// if all values are less than cur then its time to push the current inside dp
            if (itr == dp.end())
                dp.push_back(cur);
            
			// else if it is greater then replace the value already present at itr index with cur as cur is lesser
            else if(*itr > cur){
                dp[itr - dp.begin()] = cur;
            }
        }
		
        return dp.size();
    }
};
