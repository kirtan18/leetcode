https://leetcode.com/contest/weekly-contest-223/problems/swapping-nodes-in-a-linked-list/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * ptr1 = head;
        ListNode * ptr2 = head;
        ListNode * kth = NULL;
        
        while(--k){
            ptr1 = ptr1->next;
        }
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        while(ptr1){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(kth->val,ptr2->val);
        return head;
    }
};
