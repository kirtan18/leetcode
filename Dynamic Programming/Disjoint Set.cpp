union(1,2)
union(2,3)
union(4,5)
union(6,7)
union(5,6)
union(3,7)
  
      //////////////////////////////////////////////  Time : (4alpa) = O(4)    , Space : O(n) /////////////////////////////////////////////////////////

int parent[100000];
     int rank[100000];

     void mekset(){
        for (int i=1 ;i <= 100000 ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
     }

     void findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
     }

     void union(int u,int v){
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
     
    makeset();
    int m;cin >> m;

    while(m--){
        int u,v;
        cin >> u >> v;
        union(u,v);
    }
  // if 2 & 3 belong to same comp or not ?
    
    if(findPar(2) != findPar(3)){
        cout << "DIFF";
    }
    else{
        cout << "SAME";
    }   
    
}
