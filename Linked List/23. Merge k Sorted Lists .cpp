class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // priority queue to store all elements 
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i = 0 ; i<lists.size() ; i++ )
        {
            // First node of every list
            
            ListNode *temp = lists[i];
            
            // Push all values into priority queue
            
            while(temp)
            {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        
        // all the elements are sort now
        // ans node to track first node 
        
        ListNode *ans = new ListNode();
        ListNode *temp = ans;
        
        while(!pq.empty())
        {
            // put all the values into one list
            
            temp->next = new ListNode( pq.top() );
            pq.pop();
            temp = temp->next;
            
        }
        
        return ans->next;
        
    }
};
