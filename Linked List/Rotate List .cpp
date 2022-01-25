class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL || k==0)
            return head;
        
        ListNode *fptr = head;
        
        int n = 0;
        while(fptr)
        {
            n++;
            fptr = fptr->next;
        }
        
        if(k>n)
            k = k % n;
        
        fptr = head;
        
        ListNode *sptr = NULL;
        
        int count = 0;
        
        while(fptr!=NULL && count<k)
        {
            fptr = fptr->next;
            count++;
        }
        
        if(fptr==NULL)
            return head;
        
        sptr = head;
        
        while( fptr->next!=NULL && sptr!=NULL)
        {
            fptr = fptr->next;
            sptr = sptr->next;
        }
        
        fptr->next = head;
        head = sptr->next;
        sptr->next = NULL;
        
        return head;
        
    }
};
