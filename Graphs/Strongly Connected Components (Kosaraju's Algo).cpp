https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#



class Solution
{   
    vector<int>order;
    
    void dfs(int src , vector<int>&vis , vector<int> g[]){
        vis[src] = 1;
        for(auto x : g[src]){
            if(!vis[x]){
                dfs(x,vis,g);
            }
        }
        order.push_back(src);
    }
    
    void rdfs(int node , vector<int>&vis1 , vector<int>rev[]){
        vis1[node] = 1;
        
        for(auto x : rev[node]){
            if(!vis1[x]){
                rdfs(x,vis1,rev);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        order.clear();
        vector<int>rev[V];
        
        // Reverse graph
        for(int i = 0 ; i < V ; i++){
            for(auto x : adj[i]){
                rev[x].push_back(i);
            }
        }
        
        // push in stack using toposort
        vector<int>vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
        
        // orderlist into usign by last to first and check in reverse graph
        vector<int>vis1(V,0);
        int cnt = 0;
        for(int i = V-1 ; i >= 0 ; i--){
            if(!vis1[order[i]]){
                rdfs(order[i] , vis1 , rev);
                cnt++;
            }
        }
        
        return cnt;
    }
};
