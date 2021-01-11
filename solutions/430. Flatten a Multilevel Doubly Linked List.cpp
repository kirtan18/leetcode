/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
/*   time : O(n)   &&   space : O(1)   
     link: https://www.youtube.com/watch?v=RIyPgR7AF7M
 */
​
​
class Solution {
     Node* flatten_helper(Node* head) {
       Node*curr = head;
        Node*tail = head; 
      
       while(curr){
            Node*child = curr->child;
             Node*next = curr->next;
           
            if(child){
                 Node*_tail = flatten_helper(child);
                 
                 _tail->next = next;
                 if(next) next->prev = _tail;
                 curr->next = child;
                child->prev = curr;
                 curr->child = NULL;
                 curr = tail;
             }
           else
