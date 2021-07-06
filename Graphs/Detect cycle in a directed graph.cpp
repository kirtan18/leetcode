// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


///////////////////////////////////////  BFS  ,  T.C = O(N+E)  , S.C = O(2n) /////////////////////////////////////////


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	queue<int>q;
	   	vector<int>indeg(V,0);
	   	
	   	for(int i = 0 ; i < V ; i++){
	   	    for(auto it : adj[i]){
	   	        indeg[it]++;
	   	    }
	   	}
	   	
	   	for(int i = 0 ; i < V ; i++){
	   	    if(indeg[i] == 0){
	   	        q.push(i);
	   	    }
	   	}
	   	
	   	int cnt = 0;
	   	
	   	while(!q.empty()){
	   	    int node = q.front();
	   	    q.pop();
	   	    cnt++;
	   	    
	   	    for(auto it : adj[node]){
	   	        indeg[it]--;
	   	        if(indeg[it] == 0){
	   	            q.push(it);
	   	        }
	   	    }
	   	}
	   	
	   	if(cnt == V)return false;
	   	return true;
	   	
	}
};

/////////////////////////////////////////////////////////   DFS  || T.C =  O(N+E)  || S.C = O(2N)  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


class Solution
{ 
    bool checkCycle(int node, vector<int>adj[] , vector<bool>&vis,vector<bool>&dfsVis){
         
          vis[node] = 1;
          dfsVis[node] = 1;
          
          for(auto it : adj[node]){
              if(!vis[it]){
                  if(checkCycle(it,adj,vis,dfsVis)){
                    return true;   
                  }
              }
              else if(dfsVis[it]){
                  return true;
              }
          }
         
         dfsVis[node] = 0; 
         return false;         
    }
    
     
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool>vis(V+1,0);
	   	vector<bool>dfsVis(V+1,0);
  	
	   	for(int i = 0 ; i < V-1 ; i++){
	   	    if(!vis[i]){
	   	        if(checkCycle(i,adj,vis,dfsVis)){
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
};







