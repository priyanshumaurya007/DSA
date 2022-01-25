class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL)
            return head;
        
        ListNode *curr = head;
        
        while(curr->next != NULL)
        {
            if(curr->next->val == curr->val)
            {
                ListNode * temp = curr->next->next;
                delete(curr->next);
                curr->next = temp;
            }
            else
                curr = curr->next;
        }
        
        return head;
        
    }
};
