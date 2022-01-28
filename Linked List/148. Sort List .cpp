class Solution {
public:
    
    // merge 2 list function
    
    ListNode *merge( ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        
        while( l1 && l2)
        {
            if( l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            
            prev = prev->next;
        }
        
        if(l1)
            prev->next = l1;
        if(l2)
            prev->next = l2;
        
        return dummy->next;
    }
    
    // function for divide and conquer
    
    ListNode *mergesort( ListNode *head)
    {
        // is list contains 1 or 2 
        
        if( head==NULL || head->next==NULL )
            return head;
        
        // finding mid node
        
        ListNode *fast = head , *slow = head , *p=NULL;
        
        while( fast && fast->next )
        {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        p->next = NULL;
        
        // divide and conquer 
        
        ListNode *l1 = mergesort(head);
        ListNode *l2 = mergesort(slow);
        
        return merge(l1, l2);
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(!head)
            return head;
        
        return mergesort(head);
        
    }
};
