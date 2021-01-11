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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int len = 0; 
      ListNode* tmp = head; 
    while (tmp != NULL) { 
        len++; 
        tmp = tmp->next;  
    } 
      
  
    if (n > len)  
    {      
        return head;  
    } 
      
   
    else if (n == len) {      
        return head->next;  
          
    } 
    else 
    {     
        int diff = len - n;           
        ListNode* prev= NULL;        
