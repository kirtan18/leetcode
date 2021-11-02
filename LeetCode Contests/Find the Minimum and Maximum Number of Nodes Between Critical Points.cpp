https://leetcode.com/contest/weekly-contest-265/problems/minimum-operations-to-convert-number/



class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = INT_MAX , last = 0 , prev_val = head->val , min_diff = INT_MAX;
        
        int i = 0;
        while(head->next != NULL){
            if(max(prev_val,head->next->val) < head->val || 
               min(prev_val,head->next->val) > head->val){
                
                if(last != 0){
                    min_diff = min(min_diff,i - last);
                }
                first = min(first,i);
                last  = i; 
            } 
            prev_val = head->val;
            head = head->next;
            i++;
        }
        
        if(min_diff == INT_MAX){
            return {-1,-1};
        }
        return {min_diff,last-first};
    }
};
