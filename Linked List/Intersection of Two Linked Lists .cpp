class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int count1=0 , count2=0;
        
        ListNode *curr = headA;
        
        while(curr!=NULL)
        {
            count1++;
            curr = curr->next;
        }
        
        curr = headB;
        
        while(curr!=NULL)
        {
            count2++;
            curr = curr->next;
        }
        
        int d = abs(count1-count2);
        
        if(count1>count2)
        {
            while(d--)
                headA = headA->next;
        }
        else if(count2>count1)
        {
            while(d--)
                headB = headB->next;
        }
        
        while( headA!=NULL && headB!=NULL)
        {
            if(headA==headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
        
    }
};
