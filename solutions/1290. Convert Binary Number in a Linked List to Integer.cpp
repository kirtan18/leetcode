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
#include<vector>
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
     
        
        while(temp != NULL){
            len++;
            temp = temp->next;            
        }
        
        int ans =0;
        temp = head;
        
        while(temp != NULL){
            ans += temp->val * (1 << (len -1));
            temp = temp->next;
            len--;
        }
        return ans;
        
    }
};
