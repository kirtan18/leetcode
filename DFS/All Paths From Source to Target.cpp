https://leetcode.com/problems/all-paths-from-source-to-target/

/////////////////////////////////////////// T.C = O(N+E) || S.C = O(N) ///////////////////////////////////////////////////////////////////////

class Solution {
    
    void dfs(vector<vector<int>>& graph , vector<vector<int>>&ans, vector<int>&vis , int node){
        vis.push_back(node);
        
        if(node == graph.size()-1){
            ans.push_back(vis);
        }
        else{
            for(auto it : graph[node]){
                dfs(graph,ans,vis,it);
            }
        }
        vis.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>vis;
        dfs(graph,ans,vis,0);
        return ans;
    }
};
