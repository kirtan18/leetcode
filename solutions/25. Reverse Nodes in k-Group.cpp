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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)return head;
        
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *cur = dummy , *pre = dummy , *next = dummy;
        int cnt = 0;
        
        while(cur->next != NULL){
            cnt++;
            cur = cur->next;
        }
        
        while(cnt >= k){
            cur = pre->next;
            next = cur->next;
            
            for(int i = 1 ; i < k ; i++){
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }  
            pre = cur;
            cnt -= k;
                
        }
        return dummy->next;
    }
};
​
​
​
​
​
​
​
​
​
​
​
