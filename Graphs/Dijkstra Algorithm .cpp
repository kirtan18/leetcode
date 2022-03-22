
///////////////// T.C = O(NLogn) || S.C = O(N) + O(N)  ///////////////////////////////////////////


vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >pq;//(dist,from)
        
        vector<int>dist(n+1,INT_MAX);
        
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int next = it[0];
                int next_dist = it[1];
                
                if(dist[next] > dist[node] + next_dist){
                    dist[next] = dist[node] + next_dist;
                    pq.push({dist[next],next});
                }
            }
        }
        
        return dist;
    }
