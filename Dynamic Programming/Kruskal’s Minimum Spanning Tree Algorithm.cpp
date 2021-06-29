// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

 ////////////////////////////////////////  Time : O(mlogm) + O(m * O(4)) = O(mlogm)    , space : O(m) + O(m) + O(n)  = O(n)/////////////////////////////////
     struct node{
        int u;
        int v;
        int wt;

        node(int first , int second , int weight){
            u = first;
            v = second;
            wt = weight;
        }
     }

     bool comp(node a ,node b){
        return a.wt < b.wt;
     }

     void findPar(int node  , vector<int>&parent){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
     }

     void union(int u,int v,vector<int>&parent ,vector<int>&rank){
        u = findPar(u);
        v = findPar(v);
         
        if(rank[u] < rank[v]){
            parent[u] = v;
        } 
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }

     }


void solve() {
     
     int n,m;
     cin >> n >> m;

     vector<node>edges;

     for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
     }

     sort(edges.begin() , edges.end() , comp);

     vector<int>parent(n);

     for(int i = 0 ; i < n ; i++){
        parent[i] = i;
     }

     vector<int>(n,0);
     
     int cost = 0;

     vactor<pair<int,int>>mst;

     for(auto it : edges){
        if(findPar(it.v , parent) != findPar(it.u , parent)){
            cost += it.wt;

            mst.push_back({it.u , it.v});
            union(it.u,it.v,parent,rank);
        }
     }
     
     cout << cost<<"\n";

     for(auto it : mst){
        cout << it.first << " " << it.second << "\n";
      }
    
}
