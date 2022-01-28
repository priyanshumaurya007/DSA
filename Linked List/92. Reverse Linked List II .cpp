class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        // if list is empty
        
        if(head == NULL)
            return NULL;
        
        // first reach to left pointer
        
        ListNode *curr = head , *prev = NULL;
        while(left>1)
        {
            prev = curr;
            curr = curr->next;
            right--;
            left--;
        }
        
        // reverse of list till we reach to right pointer
        
        ListNode *con = prev , *tail = curr;
        
        
        while(right>0)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            right--;
        }
        
        // adjusts of final connections
        
        if(con)
            con->next = prev;
        else
            head = prev;
        
        tail->next = curr;
        
        return head;
            
        
    }
};
