class Solution {
public:
    void reorderList(ListNode* head) 
    {
        // base case : list is empty 
        
        if( !head )
            return;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // finding middle of the list
        
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        ListNode *prev = NULL;
        ListNode *half = slow;
        
        // reversing the last half list 
        
        while( half )
        {
            ListNode * temp = half->next;
            half->next = prev;
            prev = half;
            half = temp;
        }
        
        half = prev;
        
        // merge both the halfs
        
        while( head && half )
        {
            ListNode *next1 = head->next;
            ListNode *next2 = half->next;
            head->next = half;
            head = next1;
            half->next = head;
            half = next2;
            
        }
        
        // Base case : closing when we had even length arrays
        
        if( head && head->next )
            head->next->next = NULL;
        
    }
};
