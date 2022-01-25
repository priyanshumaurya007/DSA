class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head || head->next==NULL)
            return NULL;
        int count = 0;
        
        ListNode *curr = head;
        
        while(curr)
        {
            count++;
            curr = curr->next;
        }
        
        count = count - n ;
        
        curr = head;
        
        while(curr)
        {
            if(count==0)
                head = curr->next;
            if(count==1)
            {
                curr->next = curr->next->next;
                break;
            }
            else
                count--;
            
            curr = curr->next;
        }
        
        return head;
        
    }
};
