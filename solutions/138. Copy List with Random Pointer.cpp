         iter = head;
         Node * pseudohead = new Node(0);
         Node * copy = pseudohead;
         
         while(iter!= NULL){
             front = iter->next->next;
             
             copy->next = iter->next;
             
             iter->next = front;
             
             copy = copy->next;
             
             iter = front;  
         }
         
         return pseudohead->next;
          
     }    
};
​
/*
                      // Time com == O(N)  space == O(N)
  
  
class Solution {
public:
    unordered_map<Node*,Node*>m;   
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        if(m[head]) return m[head];
        m[head] = new Node(head->val);
        m[head]->next = copyRandomList(head->next);
        m[head]->random = copyRandomList(head->random);
        return m[head];
        
    }
};
​
*/
​
​
​
