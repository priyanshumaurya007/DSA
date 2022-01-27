class Solution {
public:
    
    ListNode* mergeTwoList( ListNode *l1 , ListNode *l2)
    {
        ListNode *c1 = l1;
        ListNode *c2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        
        while( c1 && c2)
        {
            if( c1->val <= c2->val)
            {
                prev->next = c1;
                c1 = c1->next;
                prev = prev->next;
            }
            else
            {
                prev->next = c2;
                c2 = c2->next;
                prev = prev->next;
            }
        }
        
        if( c1 )
            prev->next = c1;
        
        if(c2)
            prev->next = c2;
        
        return dummy->next;
    }
    
    ListNode* mergeKLists( vector<ListNode*> lists , int low , int high)
    {
        if( low > high )
            return NULL;
        
        if( low == high )
            return lists[low];
        
        int mid = ( low+ high ) / 2;
        
        ListNode * l1 = mergeKLists( lists, low , mid);
        ListNode * l2 = mergeKLists( lists, mid+1 , high);
        
        return mergeTwoList ( l1 , l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
            return NULL;
        
        return mergeKLists(lists, 0 , lists.size()-1);
        
    }
};
