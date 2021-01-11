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
//https://www.geeksforgeeks.org/remove-occurrences-duplicates-sorted-linked-list/
​
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* dummy = new ListNode(-1);
      ListNode* prev = NULL;
      ListNode* dummyPtr = dummy;
      ListNode* nextNode;
      while(head){
         if(!head->next || head->val != head->next->val){
            dummyPtr->next = head;
            ListNode* temp = head->next;
            head->next = NULL;
            head = temp;
            dummyPtr = dummyPtr->next;
         } else {
            prev = head;
            head = head->next;
            while(head && head->val == prev->val){
               prev = head;
               head = head->next;
            }
         }
      }
