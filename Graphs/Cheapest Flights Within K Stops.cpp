https://leetcode.com/problems/cheapest-flights-within-k-stops/


/////////////////////////////////////////////////////////////// TLE ////////////////////////////////////////////////////////////////


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>>g(n);
        
        for(auto x : flights){
            g[x[0]].push_back({x[1],x[2]});
        }
        
        priority_queue< tuple<int,int,int>, 
                        vector<tuple<int,int,int>>,
                        greater<tuple<int,int,int> > > pq;
        
        pq.push(make_tuple(0,src,0)); // (cost,node,stop)
        
        while(!pq.empty()){
            
            auto [cost,node,stop] = pq.top();
            pq.pop();
            
            if(node == dst)return cost;
            if(stop > k)continue;
            
            for(auto child : g[node]){
                auto [v,w] = child;
                pq.push(make_tuple(cost+w,v,stop+1));
            }   
        }
        return -1;
    }
};


////////////////////////////////////////////////////// Optimal ////////////////////////////////////////////////////////////////

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>>g(n);
        
        for(auto x : flights){
            g[x[0]].push_back({x[1],x[2]});
        }
        
        priority_queue< tuple<int,int,int>, 
                        vector<tuple<int,int,int>>,                                                            
                        greater<tuple<int,int,int> > > pq;
        
        vector<int> dist(n+1, INT_MAX);   //to avoid tle
	
        pq.push(make_tuple(0,src,0)); // (cost,node,stop)
        
        while(!pq.empty()){
            
            auto [cost,node,stop] = pq.top();
            pq.pop();
            
            if(dist[node] < stop) continue;  // to avoid tle
		    dist[node]= stop;
            if(node == dst)return cost;
            if(stop>k)continue;
            
            for(auto child : g[node]){
                auto [v,w] = child;
                pq.push(make_tuple(cost+w,v,stop+1));
            }   
        }
        return -1;
    }
};

