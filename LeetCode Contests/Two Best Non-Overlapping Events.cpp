https://leetcode.com/contest/biweekly-contest-64/problems/two-best-non-overlapping-events/

/////////////////////// Brute Force || TLE  ///////////////////////////

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            int curr = events[i][2];
            int mx = 0;
            for(int j=0;j<n;j++){
                if(i != j && events[j][0] > events[i][1]){
                    mx = max(mx,events[j][2]);
                }
            }
            ans = max(ans,curr + mx);
        }
        return ans;
    }
};

/////////////////// Optimal ///////////////////////////

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0;
        int n = events.size();
        
        sort(events.begin(),events.end(),[](vector<int>&a , vector<int>&b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        
        vector<int>mxright(n,0);
        mxright[n-1] = events[n-1][2];
        
        for(int i=n-2;i>=0;i--){
            mxright[i] = max(events[i][2],mxright[i+1]);
        }
        
        for(int i=0;i<n;i++){
            int endTime = events[i][1];
            int l = i+1,r = n-1;
            int p = -1;
            
            while(l <= r){
                int mid = l + (r-l)/2;
                if(events[mid][0] > endTime){
                    p = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            
            if(p != -1){
                ans = max(ans,events[i][2] + mxright[p]);
            }
            ans = max(ans,events[i][2]);
        }
        return ans;
    }
};
