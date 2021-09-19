https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/



void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
   
    for (k = 0; k < V; k++) {
        
        for (i = 0; i < V; i++) {
            
            for (j = 0; j < V; j++) {
                
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    
}
