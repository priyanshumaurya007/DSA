class Solution {
public:
    // function to return total number of nodes
    
    int countNodes( ListNode *curr)
    {
        int count = 0;
        
        while(curr)
        {
            count++;
            curr = curr->next;
        }
        
        return count;
    }
    
    // function to return Kth node
    
    ListNode* kthNode( ListNode* curr , int k)
    {
        while( k-- && curr)
        {
            curr = curr->next;
        }
        
        return curr;
    }
    
    // main swap function
    
    ListNode* swapNodes(ListNode* head, int k) 
    {
        // if list is empty 
        
        if ( head == NULL )
            return head;
        
        int count =  countNodes(head);
        
        ListNode *first = kthNode( head , k-1);
        ListNode *second = kthNode( head , count-k );
        
        // swapping of values of the kth node from both the end;
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
        
        return head;
        
    }
};
