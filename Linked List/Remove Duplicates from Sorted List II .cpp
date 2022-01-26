class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if( head == NULL || head->next == NULL)
            return head;
        
        // to track head
        
        ListNode *dummy = new ListNode(0,head);
        
        ListNode *prev = dummy;
        
        while( head != NULL )
        {
            // if value is same as next 
            // skip all duplicates
            
            if(head->next!=NULL && head->val == head->next->val)
            {
            
                while(head->next!=NULL && head->val == head->next->val)
                {
                    head = head->next;
                }
                
               prev->next = head->next;
                
            }
            else
            {
                // otherwise, move prev to its next position 
                
                prev = prev->next;
                
            }
            
            head = head->next;
        }
        
        return dummy->next;
        
    }
};
