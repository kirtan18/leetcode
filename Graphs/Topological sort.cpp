// https://practice.geeksforgeeks.org/problems/topological-sort/1

   


  	vector<int> topoSort(int V, vector<int> adj[]){
	    
	    queue<int>q;
	    vector<int>indegre(V,0);
	    
	    for(int i = 0 ; i < V ; i++){
	       for(auto it : adj[i]){
	           indegre[it]++;
	       }
	    } 
	   
	   for(int i = 0  ; i < V ; i++){
	       if(indegre[i] == 0){
	           q.push(i);
	       }
	   } 
	   
	   vector<int>topo;
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       topo.push_back(node);
	       for(auto it : adj[node]){
	           indegre[it]--;
	           if(indegre[it] == 0){
	               q.push(it);
	           }
	       }
	    }
	   
	    return topo;  
 	}
