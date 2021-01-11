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
    
     // 1st method
    ListNode* partition(ListNode* head, int x) {
  
         ListNode* dummy1 = new ListNode(-1);
      ListNode* dummy2 = new ListNode(-1);
      ListNode* dummyPtr1 = dummy1;
      ListNode* dummyPtr2 = dummy2;
      while(head){
         if(head->val < x){
            dummyPtr1->next = new ListNode(head->val);
            dummyPtr1 = dummyPtr1->next;
         }
         else{
            dummyPtr2->next = new ListNode(head->val);
            dummyPtr2 = dummyPtr2->next;
         }
         head = head->next;
      }
      dummyPtr1->next = dummy2->next;
      return dummy1->next;
    }
};
