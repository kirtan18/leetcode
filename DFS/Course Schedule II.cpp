https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int n , vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<int> adj[n]; 
        vector<int>indeg(n,0);
        
       for(int i =0; i< prerequisites.size(); i++ ){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i =0; i < prerequisites.size(); i++){
            indeg[prerequisites[i][0]]++;    
        }
        
        for(int i = 0 ; i < indeg.size() ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
             topo.emplace_back(node);
        }
        
       if(topo.size() == n){
           return topo;
       }
        return {};
    }
};
