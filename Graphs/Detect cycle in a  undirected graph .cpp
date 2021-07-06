// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


/////////////////////////////////////////////////////////////  BFS //////////////////////////////////////////////

// T.C =  O(N)   ,   S.C = O(N)

class Solution {

public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        // vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, V, adj, vis)) return true; 
	        }
	    }
	    
	    return false; 
	}
};


///////////////////////////////////////////////////////////////////  DFS ////////////////////////////////////////////////////

// T.C = O(N)  ,  S.C = O(N)

class Solution 
{  
  
    bool checkCycle(int node , int par , int V ,vector<int>&vis , vector<int>adj[]){
        
        vis[node] = true;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(checkCycle(it,node,V,vis,adj)){
                    return true;
                }
            }
            else if(par != it){
                return true;
            }
        }
        return false;
    }
    
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int>vis(V+1,0);
	    
	    for(int i = 0 ; i < V ; i++){
	        if(!vis[i]){
	            if(checkCycle(i,-1,V,vis,adj)){
	                return true;
	            }
	        }
	    }
	    return false;
	}
};
