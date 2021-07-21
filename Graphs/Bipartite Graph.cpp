https://practice.geeksforgeeks.org/problems/bipartite-graph/1

//////////////////////////////////////////////////////// BFS ///////////////////////////////////////////////////////////

class Solution {
    
    bool bipartite(int src, vector<int>adj[] , int color[]){
        
        color[src] = 1;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }           
        }
        return true;   
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    memset(color,-1,sizeof color);
	    
	    for(int i=0; i < V ; i++){
	        
	        if(color[i] == -1){
	            if(!bipartite(i,adj,color)){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};


////////////////////////////////////////////////////////////////////// DFS ///////////////////////////////////////////////////////////////

bool bipartite(int src,vector<int>adj[] , int color[]){
 
     for(auto it : adj[src]){
         if(color[it] == -1){
             color[it] = 1 - color[src];
             if(!bipartite(it,adj,color)){
                 return false;
             } 
         }  else if(color[it] == color[src]){
                 return false;
             }
         
     }
     return true;   
}    

	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    memset(color,-1,sizeof(color));
	    
	    for(int i = 0 ; i < V ; i++){
	        if(color[i] == -1){
	            if(!bipartite(i,adj,color)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};



