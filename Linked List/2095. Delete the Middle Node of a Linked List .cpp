class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        // if only one value exist
        
        if( head->next == NULL)
            return NULL;
        
        // to find mid value 
        
        ListNode *slow = head;
        ListNode *prev = NULL;
        ListNode *fast = head;
        
        while( fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        // if prev is not null then assign the next value after slow pointer
        
        if(prev)
            prev->next = slow->next;
        
        return head;
        
    }
};
