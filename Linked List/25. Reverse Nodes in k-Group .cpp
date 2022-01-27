class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // if list contains <=1 node 
        
        if( !head || !head->next)
            return head;
        
        int count = 0;
        
        ListNode *curr = head;
        
        // breaking list into k nodes
        
        while( ++count < k  && curr)
            curr = curr->next;
        
        // checking whether values are less than k or end of list reached
        
        if( count < k || !curr)
            return head;
        
        // recursive call
        
        ListNode *prev = reverseKGroup( curr->next , k);
        
        curr->next = NULL;
        
        // reverse the list 
        
        curr = head;
        
        while( curr )
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        
        return prev;
        
        
    }
};
