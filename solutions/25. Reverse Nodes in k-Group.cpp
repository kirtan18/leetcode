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
 /*   time : O(n) , space : O(k) */
​
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k  == 1) return head;
        
        ListNode*dummy = new ListNode(0);
        
        dummy->next = head;
        
        ListNode*curr = dummy , *next = dummy , *pre = dummy;
        int count = 0;
        
        while(curr->next != NULL){
            curr = curr->next;
            count++;
        }
        
        while(count >= k){
          
           curr = pre->next;
           next = curr->next;
            
           for(int i= 1 ;i < k ;i++){
