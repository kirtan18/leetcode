// https://leetcode.com/problems/jump-game-iii/


///////////////////////////////////////////// BFS ////////////////////////////////////////
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size(); 
        queue<int>q;
        vector<int>vis(n,0);
        q.push(start);
        vis[start] = 1;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(arr[f] == 0)return 1;
            
            int back = f - arr[f];
            int front = f + arr[f];
            
            if(back >= 0 && vis[back] == 0){
                q.push(back);
                vis[back] = 1;
            }
            if(front<n && vis[front] == 0){
                q.push(front);
                vis[front] = 1;
            }
        }
        return 0;
    }
};

//////////////////////////////////// DFS ///////////////////////////////////////////

class Solution {
    vector<int>vis;
    bool solve(int idx,vector<int>& arr){
        if(idx<0 || idx>=arr.size())return 0;
        if(vis[idx] == 1)return 0;
        if(arr[idx] == 0)return 1;
        vis[idx] = 1;
        bool op1 = solve(idx-arr[idx],arr);
        bool op2 = solve(idx+arr[idx],arr);
        if(op1 || op2)return 1;
        return 0;
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        int n =arr.size();
        vis.resize(n,0);
        bool ans = solve(start,arr);
        return ans;
    }
};
