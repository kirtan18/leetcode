/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL)return NULL;
        ListNode * dummy = new ListNode(0);
       dummy->next =head;
        
        ListNode * Mnode = head;
        ListNode * prem = dummy;
        ListNode * Nnode = head;
        
        for(int i = 0 ; i < left-1 ; i++){
            prem = Mnode;
            Mnode = Mnode -> next;
        }
        
        for(int i = 0 ; i < right-1 ; i++){            
            Nnode = Nnode -> next;
        }
        
        while(Mnode != Nnode){
            prem->next =  Mnode->next;
            Mnode->next = Nnode->next;
            Nnode->next = Mnode;
            Mnode = prem->next;
        }
        return dummy->next;
    }
};
​
​
​
​
​
