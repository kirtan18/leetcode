// https://leetcode.com/problems/clone-graph/


// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
 

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2,
// and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
  
  
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).  
  
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
  
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
  
Input: adjList = [[2],[1]]
Output: [[2],[1]]  


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/////////////////////////////////////*************  1st  Method ************************///////////////////////////////////////////////////////
/////////////////////////////////////////  USING DFS Method in we can use vector ///////////////////////////////////////////////////// 

class Solution {
    
    void dfs(Node * node , Node * copy , vector<Node*>&vis){
        vis[copy->val] = copy;
        
        for(auto x : node->neighbors){
            if(vis[x->val] == NULL){
                Node * newNode = new Node(x->val);
                (copy->neighbors).push_back(newNode);
                dfs(x,newNode,vis);
            }
            else{
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
        
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        vector<Node*>vis(1000,NULL);
        Node * copy = new Node(node->val);
        dfs(node,copy,vis);
        return copy;
        
    }
};

/////////////////////////////////////*************  2nd  Method ************************///////////////////////////////////////////////////////
/////////////////////////////////////////  USING DFS Method in we can use unordered_map ///////////////////////////////////////////////////// 


class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        if(visited[node])
            return visited[node];
        
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        
        for(auto nei: node->neighbors){
            cloned->neighbors.push_back(cloneGraph(nei));
        }
        return cloned;
        
    }
};


/////////////////////////////////////*************  3rd  Method ************************///////////////////////////////////////////////////////
/////////////////////////////////////////  USING BFS Method in we can use unordered_map & queue ///////////////////////////////////////////////////// 


Node* cloneGraph(Node* node){
        if(node == NULL)
            return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> Q;
        Q.push(node);
        visited[node] = new Node(node->val);
        while(!Q.empty()){
            int n = Q.size();
            Node* curr = Q.front();
            Q.pop();
            for(auto nei: curr->neighbors){
                if(!visited[nei]){
                     visited[nei] = new Node(nei->val);
                     Q.push(nei);
                }
                visited[curr]->neighbors.push_back(visited[nei]);
            }
        }
        return visited[node];

    }
