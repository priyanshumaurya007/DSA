class Solution {
public:
    
    // helper function
    TreeNode* sortedListToBST(ListNode* head , int low, int high)
    {
        // if low becomes greater than high
        if(low>high)
            return NULL;
        
        // cal mid value
        int mid = low + (high-low)/2;
        
        // find node of middle value
        ListNode *curr = head;
        int start = low;
        
        while(start<mid)
        {
            curr = curr->next;
            start++;
        }
        
        // make TreeNode of middle value 
        TreeNode *newnode = new TreeNode(curr->val);
        
        // recursion
        newnode->left = sortedListToBST(head, low , mid -1);
        newnode->right = sortedListToBST(curr->next , mid+1 , high);
        
        // return node 
        return newnode;
    }
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        // if list is empty
        if(!head)
            return NULL;
        
        // check length of list
        ListNode *curr = head;
        int high = 0;
        while(curr->next)
        {
            high++;
            curr = curr->next;
        }
        
        // call to helper function
        return sortedListToBST(head, 0 , high);
        
    }
};
