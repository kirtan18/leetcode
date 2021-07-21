https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/


void findToposort(int node, int vis[] , stack<int>&st, vector<pair<int>> adj[]){
     
      vis[node] = 1;

      for(auto it : adj[node]){
        if(!vis[it.first]){
            findToposort(it,vis,st,adj);
        }
      }
    st.push(node);
}

int INF = INT_MIN;
void longestPath(int src,int n,vector<pair<int,int>> adj[]){
   
    int vis[n] = {0};
    stack<int>st;

    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            findToposort(i,vis,st,adj);
        }
    }

    int dist[n];

    for(int i = 0 ; i < n ; i++){
        dist[i] = INF;
    }

    dist[src] = 0;

    while(!st.empty()){

         int node = st.top();
         st.pop();

         if(dist[node] != INF){
            for(auto it : adj[node]){
                if(dist[node] + it.second > dist[it.first]){
                     dist[it.first] = dist[node] + it.second;
                }
            }
         }
    }

    for(int i  = 0 ; i < n ; i++){
        dist[i] == INF ? cout << "INF" : cout << dist[i] <<" ";
    }
}
