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
​
class Solution {
public:
    // time : O(n log k)   space : O(n)
    
    struct compare{
        
        bool operator()(ListNode* &a ,ListNode* &b){
            return a->val > b->val;
        }        
     };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*curr = NULL;
        ListNode*temp;
        
        priority_queue<ListNode* ,vector< ListNode*>, compare> pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }
        
        while(pq.empty() == false){
