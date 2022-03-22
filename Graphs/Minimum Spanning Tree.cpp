
////////////////// T.C = O(N^2) || S.C = O(N) || Brute Force /////////////

int spanningTree(int n, vector<vector<int>> adj[])
    {
        int parent[n];
        int key[n];
        int mstset[n];
        
        for(int i=0;i<n;i++){
            parent[i] = -1;
            key[i] = INT_MAX;
            mstset[i] = false;
        }
        
        key[0] = 0;
        parent[0] = -1;
        
        for(int count =  0 ; count < n-1; count++){
            
            //Find minimum in key array
            int mini = INT_MAX,u;
            for(int i=0;i<n;i++){
                if(mstset[i] == false && key[i] < mini){
                    mini = key[i];
                    u = i;
                }
            }
            
            mstset[u] = true;
            
            //Now we can traverse on u's edges
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                
                if(mstset[v] == false && weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi += key[i];
        }
        return maxi;
    }

//////////////////////////// Optimal || T.C = O(NlogN) || S.C = O(N) ///////////////////


 int spanningTree(int n, vector<vector<int>> adj[])
    {
        int parent[n];
        int key[n];
        bool mstset[n];
        
        for(int i=0;i<n;i++){
            parent[i] = -1;
            key[i] = INT_MAX;
            mstset[i] = false;
        }
        
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>> >pq;
        
        key[0] = 0;
        parent[0] = -1;
        pq.push({0,0});
        
        while(!pq.empty()){
            
            int u = pq.top().second;
            pq.pop();
            
            mstset[u] = true;
            
            //Now we can traverse on u's edges
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                
                if(mstset[v] == false && weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v],v});
                }
            }
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi += key[i];
        }
        return maxi;
    }
