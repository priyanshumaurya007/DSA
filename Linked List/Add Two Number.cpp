class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *dummy = new ListNode(0);
        
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else
        {
            ListNode *r = dummy;
            int sum = 0, carry =0;
            while( l1 != NULL || l2 != NULL )
            {
                sum = ( l1==NULL ? 0 : l1->val) + ( l2==NULL ? 0 : l2->val ) + carry ;
                carry = sum/10;
                sum = sum % 10;
                r->next = new ListNode(sum);
                r = r->next;
                
                if(l1 != NULL)
                    l1 = l1->next;
                if(l2 != NULL)
                    l2 = l2->next;
                
            }
            
            if(carry > 0)
                r->next = new ListNode(carry);
                
        }
        
        return dummy->next;
        
    }
};
